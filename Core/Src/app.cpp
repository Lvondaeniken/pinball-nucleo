/*
 * app.cpp
 *
 *  Created on: Feb 21, 2023
 *      Author: lukasvondaniken
 */

#include "app.h"
#include "events.h"
#include "gpio.h"
#include "iodef.h"
#include "main.h"
#include "stm32f0xx_hal_gpio.h"
#include "usart.h"

namespace
{
    const uint32_t cDelayMs = 1000;
    void send(const char* pText)
    {
        HAL_UART_Transmit(&huart2, (uint8_t*)pText, sizeof(pText), 10);
    }
    void delayMs(uint32_t durationMs)
    {
        for (uint64_t i = 1000*durationMs; i > 0; i--)
        {
        }
    }
}
namespace Pinball
{
    void poll_bumpers();
    void poll_flipper();
    void poll_targets();
    void poll_slingshot();
    void poll_ballshooter();

    bool isSet(Events::ESource source)
    {
        using namespace Events;
        switch (source)
        {
        case ESource::eBumper1:
        {
            return (HAL_GPIO_ReadPin(BUMPER1_SWITCH_GPIO_Port, BUMPER1_SWITCH_Pin) == 0);
        }
        case ESource::eBumper2:
        {
            return (HAL_GPIO_ReadPin(BUMPER2_SWITCH_GPIO_Port, BUMPER2_SWITCH_Pin) == 0);
        }
        case ESource::eBumper3:
        {
            return (HAL_GPIO_ReadPin(BUMPER3_SWITCH_GPIO_Port, BUMPER3_SWITCH_Pin) == 0);
        }
        case ESource::eKickerRight:
        {
            return (HAL_GPIO_ReadPin(RIGHT_KICKER_SWITCH_GPIO_Port, RIGHT_KICKER_SWITCH_Pin) == 0);
        }
        case ESource::eKickerLeft:
        {
            return (HAL_GPIO_ReadPin(LEFT_KICKER_SWITCH_GPIO_Port, LEFT_KICKER_SWITCH_Pin) == 0);
        }
        case ESource::eSlingshotLeft:
        {
            return (HAL_GPIO_ReadPin(LEFT_SLINGSHOT_SWITCH_GPIO_Port, LEFT_SLINGSHOT_SWITCH_Pin) == 0);
        }
        case ESource::eSlingshotRight:
        {
            return (HAL_GPIO_ReadPin(RIGHT_SLINGSHOT_SWITCH_GPIO_Port, RIGHT_SLINGSHOT_SWITCH_Pin) == 0);
        }
        case ESource::eTarget1:
        {
            return (HAL_GPIO_ReadPin(TARGET1_GPIO_Port, TARGET1_Pin) == 0);
        }
        case ESource::eTarget2:
        {
            return (HAL_GPIO_ReadPin(TARGET2_GPIO_Port, TARGET2_Pin) == 0);
        }
        case ESource::eTarget3:
        {
            return (HAL_GPIO_ReadPin(TARGET3_GPIO_Port, TARGET3_Pin) == 0);
        }
        case ESource::eBallshooter:
        {
            return (HAL_GPIO_ReadPin(BALLSHOOTER_SWITCH_GPIO_Port, BALLSHOOTER_SWITCH_Pin) == 0);
        }

        default:
            return false;
        };
    }

    void triggerCoil(Events::ECoil coil)
    {
        using namespace Events;
        switch (coil)
        {
        case ECoil::eBumper1:
        {
            HAL_GPIO_WritePin(BUMPER1_COIL_GPIO_Port, BUMPER1_COIL_Pin, (GPIO_PinState)1);
            delayMs(cDelayMs);
            HAL_GPIO_WritePin(BUMPER1_COIL_GPIO_Port, BUMPER1_COIL_Pin, (GPIO_PinState)0);
            break;
        }
        case ECoil::eBumper2:
        {
            HAL_GPIO_WritePin(BUMPER2_COIL_GPIO_Port, BUMPER2_COIL_Pin, (GPIO_PinState)1);
            delayMs(cDelayMs);
            HAL_GPIO_WritePin(BUMPER2_COIL_GPIO_Port, BUMPER2_COIL_Pin, (GPIO_PinState)0);
            break;
        }
        case ECoil::eBumper3:
        {
            HAL_GPIO_WritePin(BUMPER3_COIL_GPIO_Port, BUMPER3_COIL_Pin, (GPIO_PinState)1);
            delayMs(cDelayMs);
            HAL_GPIO_WritePin(BUMPER3_COIL_GPIO_Port, BUMPER3_COIL_Pin, (GPIO_PinState)0);
            break;
        }
        case ECoil::eKickerLeft:
        {
            TIM1->CCR1 = 1000;
            HAL_GPIO_WritePin(LEFT_KICKER_COIL_GPIO_Port, LEFT_KICKER_COIL_Pin, (GPIO_PinState)1);
            delayMs(cDelayMs);
            HAL_GPIO_WritePin(LEFT_KICKER_COIL_GPIO_Port, LEFT_KICKER_COIL_Pin, (GPIO_PinState)0);
            TIM1->CCR1 = 500; // change dutycycle for holding the flipper
            break;
        }
        case ECoil::eKickerRight:
        {
            TIM1->CCR2 = 1000;
            HAL_GPIO_WritePin(RIGHT_KICKER_COIL_GPIO_Port, RIGHT_KICKER_COIL_Pin, (GPIO_PinState)1);
            delayMs(cDelayMs);
            HAL_GPIO_WritePin(RIGHT_KICKER_COIL_GPIO_Port, RIGHT_KICKER_COIL_Pin, (GPIO_PinState)0);
            TIM1->CCR2 = 500; // change dutycycle for holding the flipper
            break;
        }
        case ECoil::eBallshooter:
        {
            HAL_GPIO_WritePin(BALLSHOOTER_COIL_GPIO_Port, BALLSHOOTER_COIL_Pin, (GPIO_PinState)1);
            delayMs(cDelayMs);
            HAL_GPIO_WritePin(BALLSHOOTER_COIL_GPIO_Port, BALLSHOOTER_COIL_Pin, (GPIO_PinState)0);
            break;
        }
        case ECoil::eSlingshotLeft:
        {
            HAL_GPIO_WritePin(LEFT_SLINGSHOT_COIL_GPIO_Port, LEFT_SLINGSHOT_COIL_Pin, (GPIO_PinState)1);
            delayMs(cDelayMs);
            HAL_GPIO_WritePin(LEFT_SLINGSHOT_COIL_GPIO_Port, LEFT_SLINGSHOT_COIL_Pin, (GPIO_PinState)0);
            break;
        }
        case ECoil::eSlingshotRight:
        {
            HAL_GPIO_WritePin(RIGHT_SLINGSHOT_COIL_GPIO_Port, RIGHT_SLINGSHOT_COIL_Pin, (GPIO_PinState)1);
            delayMs(cDelayMs);
            HAL_GPIO_WritePin(RIGHT_SLINGSHOT_COIL_GPIO_Port, RIGHT_SLINGSHOT_COIL_Pin, (GPIO_PinState)0);
            break;
        }
        case ECoil::eMagazine:
        {
            HAL_GPIO_WritePin(MAGAZIN_COIL_GPIO_Port, MAGAZIN_COIL_Pin, (GPIO_PinState)1);
            delayMs(cDelayMs);
            HAL_GPIO_WritePin(MAGAZIN_COIL_GPIO_Port, MAGAZIN_COIL_Pin, (GPIO_PinState)0);
            break;
        }
        default:
        {
        }
        };
    }

    void streamEvents()
    {
        while (1)
        {
            poll_bumpers();
            poll_flipper();
            poll_targets();
            poll_slingshot();
            poll_ballshooter();
        };
    }

    void poll_bumpers(void)
    {
        static uint8_t bmp1_flag = 1;
        static uint8_t bmp2_flag = 1;
        static uint8_t bmp3_flag = 1;
        // bumper 1
        if (isSet(Events::ESource::eBumper1) && bmp1_flag)
        {
            bmp1_flag = 0;
            send(Events::bmp1);
            triggerCoil(Events::ECoil::eBumper1);
        }
        if (!isSet(Events::ESource::eBumper1) && bmp1_flag == 0)
        {
            bmp1_flag = 1;
        }
        // bumper 2
        if (isSet(Events::ESource::eBumper2) && bmp2_flag)
        {
            bmp2_flag = 0;
            send(Events::bmp2);
            triggerCoil(Events::ECoil::eBumper2);
        }
        if (!isSet(Events::ESource::eBumper2) && bmp2_flag == 0)
        {
            bmp2_flag = 1;
        }
        // bumper 3
        if (isSet(Events::ESource::eBumper3) && bmp3_flag)
        {
            bmp3_flag = 0;
            send(Events::bmp3);
            triggerCoil(Events::ECoil::eBumper3);
        }
        if (!isSet(Events::ESource::eBumper3) && bmp3_flag == 0)
        {
            bmp3_flag = 1;
        }
    }

    void poll_flipper(void)
    {
        static uint8_t btn_flipperL_flag = 1;
        static uint8_t btn_flipperR_flag = 1;

        // left
        if (isSet(Events::ESource::eKickerLeft) && btn_flipperL_flag)
        {
            btn_flipperL_flag = 0;
            triggerCoil(Events::ECoil::eKickerLeft);
            send(Events::flipLeft);
        }
        if (!isSet(Events::ESource::eKickerLeft) && btn_flipperL_flag == 0)
        {
            TIM1->CCR1 = 0;
            btn_flipperL_flag = 1;
        }

        // right
        if (isSet(Events::ESource::eKickerRight) && btn_flipperR_flag)
        {
            btn_flipperR_flag = 0;
            triggerCoil(Events::ECoil::eKickerRight);
            send(Events::flipRight);
        }
        if (!isSet(Events::ESource::eKickerRight) && btn_flipperR_flag == 0)
        {
            TIM1->CCR2 = 0;
            btn_flipperR_flag = 1;
        }
    }

    void poll_slingshot(void)
    {
        static uint8_t btn_slingL_flag = 1;
        static uint8_t btn_slingR_flag = 1;
        // SLINGSHOT L
        if (isSet(Events::ESource::eSlingshotLeft) && btn_slingL_flag)
        {
            triggerCoil(Events::ECoil::eSlingshotLeft);
            btn_slingL_flag = 0;
            send(Events::slingshotLeft);
        }
        if (!isSet(Events::ESource::eSlingshotLeft) && btn_slingL_flag == 0)
        {
            btn_slingL_flag = 1;
        }
        // SLINGSHOT R
        if (isSet(Events::ESource::eSlingshotRight) && btn_slingR_flag)
        {
            triggerCoil(Events::ECoil::eSlingshotRight);
            btn_slingR_flag = 0;
            send(Events::slingshotRight);
        }
        if (!isSet(Events::ESource::eSlingshotRight) && btn_slingR_flag == 0)
        {
            btn_slingR_flag = 1;
        }
    }

    void poll_ballshooter(void)
    {
        // ballshooter
        static uint8_t ballshooter_flag = 1;
        if (isSet(Events::ESource::eBallshooter) && ballshooter_flag)
        {
            ballshooter_flag = 0;
            triggerCoil(Events::ECoil::eBallshooter);
            send(Events::ballshooter);
        }
        if (!isSet(Events::ESource::eBallshooter) && ballshooter_flag == 0)
        {
            ballshooter_flag = 1;
            triggerCoil(Events::ECoil::eMagazine);
        }
    }

    void poll_targets(void)
    {
        static bool t1 = true;
        static bool t2 = true;
        static bool t3 = true;
        if (isSet(Events::ESource::eTarget1) && t1)
        {
            t1 = false;
            send(Events::target1);
        }
        if (!isSet(Events::ESource::eTarget1) && !t1)
        {
            t1 = true;
        }
        if (isSet(Events::ESource::eTarget2) && t2)
        {
            t2 = false;
            send(Events::target2);
        }
        if (!isSet(Events::ESource::eTarget2) && !t2)
        {
            t2 = true;
        }
        if (isSet(Events::ESource::eTarget3) && t3)
        {
            t3 = false;
            send(Events::target3);
        }
        if (!isSet(Events::ESource::eTarget3) && !t3)
        {
            t3 = true;
        }
    }
}
