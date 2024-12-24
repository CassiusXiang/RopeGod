/*
 * user_adc.c
 *
 *  Created on: Sep 21, 2024
 *      Author: Chang
 */

#include "user_adc.h"

/**
 * @brief: 获取
 */
uint32_t get_adc_value(void)
{
    HAL_ADC_Start(&hadc1);
    HAL_ADC_PollForConversion(&hadc1, 5);
    return HAL_ADC_GetValue(&hadc1);
}
