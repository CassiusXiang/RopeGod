/*
 * user_flash.c
 *
 *  Created on: Sep 11, 2024
 *      Author: Chang
 */

#include "user_flash_64kb.h"

/**
 * @brief 解锁Flash，擦除页
 */
void Flash_ErasePage64(void)
{
    // 解锁Flash
    HAL_FLASH_Unlock();

    // 配置擦除结构体
    FLASH_EraseInitTypeDef eraseInitStruct;
    uint32_t pageError = 0;

    // 擦除第64页
    eraseInitStruct.TypeErase = FLASH_TYPEERASE_PAGES;
    eraseInitStruct.PageAddress = 0x0800FC00; // 第64页的起始地址
    eraseInitStruct.NbPages = 1;              // 只擦除1页（1KB）

    // 执行擦除
    if (HAL_FLASHEx_Erase(&eraseInitStruct, &pageError) != HAL_OK)
    {
        // 处理擦除错误
        Error_Handler();
    }

    // 锁定Flash
    HAL_FLASH_Lock();
}
/**
 * @brief 写入数据到末页
 * @param addressOffset 指定的偏移地址（32的整数倍0x20）
 * @param data 32位的数据
 */
void Flash_WriteDataToPage64(uint32_t addressOffset, uint32_t data)
{
    // 清除页数据
    Flash_ErasePage64();

    // 解锁Flash
    HAL_FLASH_Unlock();

    // 将数据写入指定偏移地址
    uint32_t address = 0x0800FC00 + addressOffset;
    if (HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, address, data) != HAL_OK)
    {
        // 写入错误处理
        Error_Handler();
        HAL_UART_Transmit(&huart1, "E01", 3, 5);
    }

    // 锁定Flash
    HAL_FLASH_Lock();
}
/**
 * @brief 读取末页数据
 * @param addressOffset 指定的偏移地址（32的整数倍0x20）
 * @return 读取到的32位数据
 */
uint32_t Flash_ReadDataFromPage64(uint32_t addressOffset)
{
    // 从指定的偏移地址读取数据
    uint32_t address = 0x0800FC00 + addressOffset;
    return *(uint32_t *)address;
}
/**
 * @brief 写入储存器配置
 * @param filterId 储存器ID
 */
void Flash_WriteFilterDataToPage64(uint32_t filterId)
{
    Flash_WriteDataToPage64(0x00000020, filterId);
}
/**
 * @brief 读取储存器配置
 * @return filterId 读取到的储存器ID
 */
uint32_t Flash_ReadFilterDataToPage64()
{
    return Flash_ReadDataFromPage64(0x00000020);
}