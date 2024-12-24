/*
 * user_can.h
 *
 *  Created on: Sep 5, 2024
 *      Author: Chang
 */

#ifndef INC_USER_CAN_H_
#define INC_USER_CAN_H_

#include "main.h"

/*macro*/
//#define TEST_MODE

/*Variable*/
extern uint32_t privateStdId;

/*function*/
void CAN_Init();
HAL_StatusTypeDef CAN_SetFilters();
HAL_StatusTypeDef CAN_SetBank1Filters(uint32_t stdId);
void CAN_SendMsg(uint8_t msgID, uint8_t frameType);
void CAN_ReadMsg(uint32_t FIFO_num);
void SERVO_MsgProcess(uint8_t *Rxdata);
void FILTER_MsgProcess(uint8_t *Rxdata);
void PRESSURE_MsgProcess(uint8_t *Rxdata, uint16_t *adcValue);
void PRESSURE_Send(uint8_t pressureId, uint16_t *adcValue);

#endif /* INC_USER_CAN_H_ */
