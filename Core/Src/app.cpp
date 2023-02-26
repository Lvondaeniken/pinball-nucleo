/*
 * app.cpp
 *
 *  Created on: Feb 21, 2023
 *      Author: lukasvondaniken
 */

#include "app.h"
#include "bumper.h"
#include "events.h"
#include "gpio.h"
#include "iodef.h"
#include "main.h"
#include "stm32f0xx_hal_gpio.h"
#include "stm32f0xx_hal_uart.h"
#include "target.h"
#include "usart.h"
#include "coil.h"
#include "switch.h"

namespace
{
    const uint32_t cDelayMs = 1000;
    const char pNewline[] = "\r\n";

    void send(const char* pText)
    {
        HAL_UART_Transmit(&huart2, (uint8_t*)pText, sizeof(pText), 10);
        HAL_UART_Transmit(&huart2, (uint8_t*)pNewline, sizeof(pNewline), 10);
    }
    void delayMs(uint32_t durationMs)
    {
        for (uint64_t i = 1000 * durationMs; i > 0; i--)
        {
        }
    }
}
namespace Pinball
{
    auto b1_sw = Switch(BUMPER1_SWITCH_Pin, BUMPER1_SWITCH_GPIO_Port);
    auto b1_coil = Coil(BUMPER1_COIL_Pin, BUMPER1_COIL_GPIO_Port);
    auto bumper1 = Bumper(1, &b1_sw, &b1_coil);

    auto b2_sw = Switch(BUMPER2_SWITCH_Pin, BUMPER2_SWITCH_GPIO_Port);
    auto b2_coil = Coil(BUMPER2_COIL_Pin, BUMPER2_COIL_GPIO_Port);
    auto bumper2 = Bumper(2, &b2_sw, &b2_coil);

    auto b3_sw = Switch(BUMPER3_SWITCH_Pin, BUMPER3_SWITCH_GPIO_Port);
    auto b3_coil = Coil(BUMPER3_COIL_Pin, BUMPER3_COIL_GPIO_Port);
    auto bumper3 = Bumper(3, &b3_sw, &b3_coil);

    auto t1_switch = Switch(TARGET1_Pin, TARGET1_GPIO_Port);
    auto target1 = Target(1, &t1_switch);

    auto t2_switch = Switch(TARGET2_Pin, TARGET2_GPIO_Port);
    auto target2 = Target(2, &t2_switch);

    auto t3_switch = Switch(TARGET3_Pin, TARGET3_GPIO_Port);
    auto target3 = Target(3, &t3_switch);

    void poll_bumpers();
    void poll_flipper();
    void poll_targets();
    void poll_slingshot();
    void poll_ballshooter();
    void poll_lightbarrier();

    bool isSet(const Part& part)
    {
        if (part.inverted)
        {
            return (HAL_GPIO_ReadPin(part.swPort, part.swPin) == 0);
        }
        else
        {
            return HAL_GPIO_ReadPin(part.swPort, part.swPin);
        }
    }

    void trigger(const Part& part)
    {
        switch (part.coil)
        {
        case ECoil::eNone:
        {
            break;
        }
        case ECoil::eKickerLeft:
        {
            TIM1->CCR1 = 1000;
            HAL_GPIO_WritePin(part.coilPort, part.coilPin, (GPIO_PinState)1);
            delayMs(cDelayMs);
            HAL_GPIO_WritePin(part.coilPort, part.coilPin, (GPIO_PinState)0);
            TIM1->CCR1 = 500; // change dutycycle for holding the flipper
            break;
        }
        case ECoil::eKickerRight:
        {
            TIM1->CCR2 = 1000;
            HAL_GPIO_WritePin(part.coilPort, part.coilPin, (GPIO_PinState)1);
            delayMs(cDelayMs);
            HAL_GPIO_WritePin(part.coilPort, part.coilPin, (GPIO_PinState)0);
            TIM1->CCR2 = 500; // change dutycycle for holding the flipper
            break;
        }
        default:
        {
            HAL_GPIO_WritePin(part.coilPort, part.coilPin, (GPIO_PinState)1);
            delayMs(cDelayMs);
            HAL_GPIO_WritePin(part.coilPort, part.coilPin, (GPIO_PinState)0);
            break;
        }
        };
    }

    void streamEvents()
    {
        while (1)
        {
            delayMs(50);
        };
    }

    void poll_flipper(void)
    {
        static uint8_t btn_flipperL_flag = 1;
        static uint8_t btn_flipperR_flag = 1;

        // left
        // if (isSet(leftKicker) && btn_flipperL_flag)
        // {
        //    btn_flipperL_flag = 0;
        //   trigger(leftKicker);
        //  send(leftKicker.serID);
        // }
        // if (!isSet(leftKicker) && btn_flipperL_flag == 0)
        // {
        //     TIM1->CCR1 = 0;
        //   btn_flipperL_flag = 1;
        //}

        // right
        // if (isSet(rightKicker) && btn_flipperR_flag)
        //{
        //   btn_flipperR_flag = 0;
        //  trigger(rightKicker);
        // send(rightKicker.serID);
        //}
        // if (!isSet(rightKicker) && btn_flipperR_flag == 0)
        //{
        //   TIM1->CCR2 = 0;
        //  btn_flipperR_flag = 1;
        // }
    }
}
