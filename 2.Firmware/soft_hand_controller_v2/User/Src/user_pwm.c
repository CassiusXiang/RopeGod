/*
 * user_pwm.c
 *
 *  Created on: Sep 11, 2024
 *      Author: Chang
 */

#include "user_pwm.h"

PWM_Channel pwm_channels[] = {
    {&htim2, TIM_CHANNEL_2},
    {&htim3, TIM_CHANNEL_1},
    {&htim3, TIM_CHANNEL_2},
    {&htim4, TIM_CHANNEL_1},
    {&htim4, TIM_CHANNEL_2},
    {&htim4, TIM_CHANNEL_3},
    {&htim4, TIM_CHANNEL_4},
    {&htim2, TIM_CHANNEL_1},
};

/**
 * @brief 设置PWM比较器
 * @param channelIndex 通道引索数
 * @param compareValue 设置通道比较器的值
 */
void PWM_SetCompare(uint8_t channelIndex, uint32_t compareValue)
{
    if (channelIndex < NUM_PWM_CHANNELS)
    {
        __HAL_TIM_SetCompare(pwm_channels[channelIndex].htim, pwm_channels[channelIndex].channel, compareValue);
    }
}
