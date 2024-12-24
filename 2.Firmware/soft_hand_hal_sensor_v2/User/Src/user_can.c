/*
 * user_can.c
 *
 *  Created on: Sep 5, 2024
 *      Author: Chang
 *  Can Baud: 1Mbps
 */
#include "user_can.h"
/*变量*/
uint32_t privateStdId = 0x00000000;

/**
 * @brief CAN初始化
 */
void CAN_Init()
{
    CAN_SetFilters();
    HAL_CAN_Start(&hcan);
    /*从Flash中读取privateStdId并写入寄存器*/
    privateStdId = Flash_ReadFilterDataToPage64();
    CAN_SetBank1Filters(privateStdId);
}
/**
 * @brief 初始化CAN控制器的FIFO0过滤器设置
 *
 * @param
 * @return 初始化状态
 */
HAL_StatusTypeDef CAN_SetFilters()
{
    CAN_FilterTypeDef canFilter;

    // 2. 设置 bank0 的筛选器
    canFilter.FilterBank = 0;
    canFilter.FilterMode = CAN_FILTERMODE_IDMASK;
    canFilter.FilterScale = CAN_FILTERSCALE_32BIT;

    // STID = 0x0000, IDE = 0, RTR = 0 (广播)
    canFilter.FilterIdHigh = (0x00FF << 5);
    canFilter.FilterIdLow = 0x0000;
    canFilter.FilterMaskIdHigh = 0xffe0;
    //     canFilter.FilterMaskIdHigh = 0x0000;
    canFilter.FilterMaskIdLow = 0x0006;
    //     canFilter.FilterMaskIdLow = 0x0000;

    canFilter.FilterFIFOAssignment = CAN_FILTER_FIFO0;
    canFilter.FilterActivation = CAN_FILTER_ENABLE;
    canFilter.SlaveStartFilterBank = 14;
    HAL_StatusTypeDef result = HAL_CAN_ConfigFilter(&hcan, &canFilter);
    return result;
}
/**
 * @brief CAN 消息发送
 * @param msgID 消息标准帧ID
 * @param frameType 帧类型
 *
 * @return
 */
void CAN_SendMsg(uint8_t msgID, uint8_t frameType)
{
    CAN_TxHeaderTypeDef TxHeader;
    TxHeader.StdId = msgID;
    TxHeader.RTR = frameType;
    TxHeader.IDE = CAN_ID_STD;
    TxHeader.DLC = 4;
    TxHeader.TransmitGlobalTime = DISABLE;

    uint8_t TxData[8];
    uint32_t TxMailbox;
    /*test code start*/
    TxData[0] = 0xFF;
    /*test code end*/

    while (HAL_CAN_GetTxMailboxesFreeLevel(&hcan) < 1) // 等待获取可用邮箱
    {
        ;
    }
    if (HAL_CAN_AddTxMessage(&hcan, &TxHeader, TxData, &TxMailbox) != HAL_OK) // 发送数据
    {
        return;
    }
}
/**
 * @brief 中断后 CAN_RX 接收到的数据读取
 * @param FIFO_num 读取的 FIFO
 *
 * @return
 */
void CAN_ReadMsg(uint32_t FIFO_num)
{
#ifdef TEST_MODE
    HAL_UART_Transmit(&huart1, "CAN_ReadMsg Succeed", 19, 10);
#endif
    CAN_RxHeaderTypeDef RxHeader;
    uint8_t RxData[8];

    if (HAL_CAN_GetRxMessage(&hcan, FIFO_num, &RxHeader, RxData) != HAL_OK)
    {
#ifdef TEST_MODE
        HAL_UART_Transmit(&huart1, "HAL_CAN_GetRxMessage Erro", 25, 10);
#endif
        return;
    }

    // TODO: RxData的处理逻辑
    uint32_t filterMatchIndex = RxHeader.FilterMatchIndex;

    // 根据不同的匹配过滤器做不同的读取操作
    switch (filterMatchIndex)
    {

    case 0: /*接收广播*/
#ifdef TEST_MODE
        HAL_UART_Transmit(&huart1, "Recived from filter 0", 21, 5);
        HAL_UART_Transmit(&huart1, RxData, sizeof(RxData), 5);
#endif
        break;

    case 1:
#ifdef TEST_MODE
        HAL_UART_Transmit(&huart1, "Recived from filter 1", 21, 5);
        HAL_UART_Transmit(&huart1, RxData, sizeof(RxData), 5);
#endif
        CAN_SetBank0Filters(RxData);
        break;
    }
}
/**
 * @brief CAN_RX接收中断重写
 * @param hcan
 *
 * @return
 */
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
#ifdef TEST_MODE
    HAL_UART_Transmit(&huart1, "RxCall", 6, 5);
#endif
    // CAN_ReadMsg(CAN_RX_FIFO0);
}
/**
 * @brief 通过 0000id 广播，设置 Bank1 筛选器
 * @param stdId 设置 Bank1 筛选器的过滤 ID，用于私有消息接收
 *
 * @return 返回设置结果
 */
HAL_StatusTypeDef CAN_SetBank1Filters(uint32_t stdId)
{
    CAN_FilterTypeDef canFilter;
    // 2. 设置 bank1 的筛选器
    canFilter.FilterBank = 1;
    canFilter.FilterMode = CAN_FILTERMODE_IDMASK;
    canFilter.FilterScale = CAN_FILTERSCALE_32BIT;

    // 设置 Filter Bank0 的 stdId
    canFilter.FilterIdHigh = (stdId << 5);
    canFilter.FilterIdLow = 0x0000;
    canFilter.FilterMaskIdHigh = 0xffe0;
    canFilter.FilterMaskIdLow = 0x0006;

    canFilter.FilterFIFOAssignment = CAN_FILTER_FIFO0;
    canFilter.FilterActivation = CAN_FILTER_ENABLE;
    HAL_StatusTypeDef result = HAL_CAN_ConfigFilter(&hcan, &canFilter);
    return result;
}
/**
 * @brief 舵机控制函数，对CAN接收到的数据进行解析，并设置PWM通道的比较器
 * @param Rxdata CAN接受到的数据
 */
void SERVO_MsgProcess(uint8_t *Rxdata)
{
    if (Rxdata[0] == 0x01)
    {
        uint8_t servoId = Rxdata[1];
        int angleData = (Rxdata[2] << 8) + Rxdata[3];
        int ccr2 = 2500 - angleData;
        PWM_SetCompare(servoId, ccr2);
    }
}
/**
 * @brief 设置私有过滤器ID，对CAN接收到的数据进行解析，并设置私有过滤器ID
 * @param Rxdata CAN接受到的数据
 */
void FILTER_MsgProcess(uint8_t *Rxdata)
{
    if (Rxdata[0] == 0x00)
    {
        uint32_t stdId = (Rxdata[1] << 8) + Rxdata[2];
        CAN_SetBank1Filters(stdId);
        Flash_WriteFilterDataToPage64(stdId);
    }
}
/**
 * @brief 用于处理接收到的获取压力命令，通过CAN返回相应传感器的数值
 * @param Rxdata CAN接受到的数据
 * @param adcValue adc数据
 *
 */
void PRESSURE_MsgProcess(uint8_t *Rxdata, uint16_t *adcValue)
{
    if (Rxdata[0] == 0x01)
    {
        CAN_TxHeaderTypeDef TxHeader;
        uint8_t TxData[8];
        uint32_t TxMailbox;
        uint16_t MessageId = 2047 - privateStdId;

        TxHeader.StdId = MessageId;      // 标准CAN ID
        TxHeader.RTR = CAN_RTR_DATA; 		// 数据帧类型
        TxHeader.IDE = CAN_ID_STD;   		// 使用标准ID
        TxHeader.DLC = 8;            		// 数据长度码，表示8字节数据
        TxHeader.TransmitGlobalTime = DISABLE;

        uint8_t pressureId = Rxdata[1];
        uint16_t adc = adcValue[pressureId];

        TxData[0] = pressureId;
        TxData[1] = (adc >> 8);
        TxData[2] = (adc & 0xFF);
        TxData[3] = 0x00;
        TxData[4] = 0x00;
        TxData[5] = 0x00;
        TxData[6] = 0x00;
        TxData[7] = 0x00;

        if (HAL_CAN_AddTxMessage(&hcan, &TxHeader, TxData, &TxMailbox) != HAL_OK)
        {
            // 发送失败处理
        }

    }
}

void PRESSURE_Send(uint8_t pressureId, uint16_t *adcValue){

    CAN_TxHeaderTypeDef TxHeader;
    uint8_t TxData[8];
    uint32_t TxMailbox;
    uint16_t MessageId = 2047 - privateStdId;

    TxHeader.StdId = MessageId;      // 标准CAN ID
    TxHeader.RTR = CAN_RTR_DATA; 		// 数据帧类型
    TxHeader.IDE = CAN_ID_STD;   		// 使用标准ID
    TxHeader.DLC = 8;            		// 数据长度码，表示8字节数据
    TxHeader.TransmitGlobalTime = DISABLE;

    uint16_t adc = adcValue[pressureId];

    TxData[0] = pressureId;
    TxData[1] = (adc >> 8);
    TxData[2] = (adc & 0xFF);
    TxData[3] = 0x00;
    TxData[4] = 0x00;
    TxData[5] = 0x00;
    TxData[6] = 0x00;
    TxData[7] = 0x00;
    if (HAL_CAN_AddTxMessage(&hcan, &TxHeader, TxData, &TxMailbox) != HAL_OK)
    {
        // 发送失败处理
    }
}
