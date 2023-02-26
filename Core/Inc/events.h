/**
 *
 */

#include "stm32f030x8.h"
namespace Pinball
{
    enum class ESwitch
    {
        eSlingshotLeft = 0,
        eSlingshotRight,
        eKickerLeft,
        eKickerRight,
        eBumper1,
        eBumper2,
        eBumper3,
        eBallshooter,
        eTarget1,
        eTarget2,
        eTarget3,
        eLightbar1,
        eLightbar2,
        eLightbar3,
        eLightbar4,
        eLightbar5,
        eLightbar6,
        eLightbar7,
        eLightbar8,

    };

    enum class ECoil
    {
        eNone,
        eSlingshotLeft,
        eSlingshotRight,
        eKickerLeft,
        eKickerRight,
        eBumper1,
        eBumper2,
        eBumper3,
        eBallshooter,
        eMagazine,
    };

    struct Part
    {
        const char* serID;
        uint16_t swPin;
        GPIO_TypeDef* swPort;
        ESwitch sw;
        bool inverted;
        uint16_t coilPin;
        GPIO_TypeDef* coilPort;
        ECoil coil;
    };
}
