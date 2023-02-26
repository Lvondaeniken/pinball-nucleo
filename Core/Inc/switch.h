
#include "gpio.h"
#include "stdint.h"

namespace Pinball
{

    class Switch
    {
    public:
        Switch(uint16_t pin, GPIO_TypeDef* port, bool inverted = true);
        ~Switch() = default;
        bool isSet();

    private:
        uint16_t m_pin;
        GPIO_TypeDef* m_port;
        bool m_inverted;
    };
}
