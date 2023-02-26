#include "switch.h"
namespace Pinball
{
    Switch::Switch(uint16_t pin, GPIO_TypeDef* port, bool inverted)
    {
        m_pin = pin;
        m_port = port;
        m_inverted = inverted;
    }

    bool Switch::isSet()
    {
        if (m_inverted)
        {

            return (HAL_GPIO_ReadPin(m_port, m_pin) == 0);
        }
        else
        {
            return (HAL_GPIO_ReadPin(m_port, m_pin) == 1);
        }
    }

}
