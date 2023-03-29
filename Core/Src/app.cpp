/*
 * app.cpp
 *
 *  Created on: Feb 21, 2023
 *      Author: lukasvondaniken
 */

#include "app.h"
#include "ballshooter.h"
#include "bumper.h"
#include "coil.h"
#include "gpio.h"
#include "iodef.h"
#include "kicker.h"
#include "log.h"
#include "slingshot.h"
#include "switch.h"
#include "target.h"

namespace
{
    const uint32_t cDelayMs = 1000;
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

    auto left_slingshot_switch = Switch(LEFT_SLINGSHOT_SWITCH_Pin, LEFT_SLINGSHOT_SWITCH_GPIO_Port);
    auto left_slingshot_coil = Coil(LEFT_SLINGSHOT_COIL_Pin, LEFT_SLINGSHOT_COIL_GPIO_Port);
    auto left_slingshot = Slingshot('l', &left_slingshot_switch, &left_slingshot_coil);

    auto right_slingshot_switch = Switch(RIGHT_SLINGSHOT_SWITCH_Pin, RIGHT_SLINGSHOT_SWITCH_GPIO_Port);
    auto right_slingshot_coil = Coil(RIGHT_SLINGSHOT_COIL_Pin, RIGHT_SLINGSHOT_COIL_GPIO_Port);
    auto right_slingshot = Slingshot('r', &right_slingshot_switch, &right_slingshot_coil);

    auto right_kicker_sw = Switch(RIGHT_KICKER_SWITCH_Pin, RIGHT_KICKER_SWITCH_GPIO_Port);
    auto right_kicker_coil = Coil(RIGHT_KICKER_COIL_Pin, RIGHT_KICKER_COIL_GPIO_Port);
    auto right_kicker = Kicker('r', &right_kicker_sw, &right_kicker_coil);

    auto left_kicker_sw = Switch(LEFT_KICKER_SWITCH_Pin, LEFT_KICKER_SWITCH_GPIO_Port);
    auto left_kicker_coil = Coil(LEFT_KICKER_COIL_Pin, LEFT_KICKER_COIL_GPIO_Port);
    auto left_kicker = Kicker('l', &left_kicker_sw, &left_kicker_coil);

    auto ballshooter_sw = Switch(BALLSHOOTER_SWITCH_Pin, BALLSHOOTER_SWITCH_GPIO_Port);
    auto ballshooter_coil = Coil(BALLSHOOTER_COIL_Pin, BALLSHOOTER_COIL_GPIO_Port);
    auto magazine_coil = Coil(MAGAZIN_COIL_Pin, MAGAZIN_COIL_GPIO_Port);
    auto ballshooter = Ballshooter(&ballshooter_sw, &ballshooter_coil, &magazine_coil);

    void streamEvents()
    {
        send("start");
        bool enable = true;
        while (1)
        {
            delayMs(2);
            char cmd = receive();
            if (cmd == 'x')
            {
                enable = true;
                send("on");
                ballshooter.enable();
                bumper1.enable();
                bumper2.enable();
                bumper3.enable();
                left_slingshot.enable();
                right_slingshot.enable();
                right_kicker.enable();
                left_kicker.enable();
                ballshooter.enable();
            }
            else if (cmd == 'o')
            {
                enable = false;
                send("off");
                ballshooter.disable();
                bumper1.disable();
                bumper2.disable();
                bumper3.disable();
                left_slingshot.disable();
                right_slingshot.disable();
                right_kicker.disable();
                left_kicker.disable();
                ballshooter.disable();
            }
            else
            {
            }

            bumper1.update();
            bumper2.update();
            bumper3.update();
            target1.update();
            target2.update();
            target3.update();
            left_slingshot.update();
            right_slingshot.update();
            right_kicker.update();
            left_kicker.update();
            ballshooter.update();
        };
    }

}
