/*
 * user_uart.c
 *
 *  Created on: Sep 10, 2024
 *      Author: Chang
 */

#include "user_uart.h"

/**
 * @brief 串口接收到数据后的处理
 * @param uart_RxData 串口接收数组指针
 *
 */
void UART_ReadMsg(uint8_t *uart_RxData)
{
}

/**
 * @brief 重写串口接收中断函数
 * @param huart 串口结构体指针
 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
//    /*接收数据处理*/
//    UART_ReadMsg(uart_RxData);
//
//    /*重启串口中断*/
//    HAL_UART_Receive_IT(&huart1, uart_RxData, 8);
}
