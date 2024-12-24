/*
 * user_flash.h
 *
 *  Created on: Sep 11, 2024
 *      Author: Chang
 */

#ifndef INC_USER_FLASH_H_
#define INC_USER_FLASH_H_

#include "main.h"

#define FilterIdAddressOffset 0x00000000

void Flash_ErasePage64(void);
void Flash_WriteDataToPage64(uint32_t addressOffset, uint32_t data);
uint32_t Flash_ReadDataFromPage64(uint32_t addressOffset);
void Flash_WriteFilterDataToPage64(uint32_t filterId);
uint32_t Flash_ReadFilterDataToPage64();

#endif /* INC_USER_FLASH_H_ */
