
#include "gpio.h"
#include "stdint.h"

namespace Pinball
{

    class Coil
    {
    public:
        enum class EState
        {
            eEnabled,
            eDisabled,
        };

        Coil(uint16_t pin, GPIO_TypeDef* port);
        ~Coil() = default;
        void enable();
        void disable();
        EState getState();

    private:
        uint16_t m_pin;
        GPIO_TypeDef* m_port;
        EState m_state;
    };
}
