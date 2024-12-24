/*
 * user_pwm.h
 *
 *  Created on: Sep 11, 2024
 *      Author: Chang
 */

#ifndef INC_USER_PWM_H_
#define INC_USER_PWM_H_

#include "main.h"

#define NUM_PWM_CHANNELS (sizeof(pwm_channels) / sizeof(pwm_channels[0]))

typedef struct
{
    TIM_HandleTypeDef *htim;
    uint32_t channel;
} PWM_Channel;

void PWM_SetCompare(uint8_t channelIndex, uint32_t compareValue);

#endif /* INC_USER_PWM_H_ */
