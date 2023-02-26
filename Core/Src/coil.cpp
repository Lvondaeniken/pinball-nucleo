#include "coil.h"

namespace Pinball
{
    Coil::Coil(uint16_t pin, GPIO_TypeDef* port)
    {
        m_pin = pin;
        m_port = port;
        m_state = EState::eDisabled;
    }

    void Coil::enable()
    {
        HAL_GPIO_WritePin(m_port, m_pin, (GPIO_PinState)1);
        m_state = EState::eEnabled;
    }
    void Coil::disable()
    {
        HAL_GPIO_WritePin(m_port, m_pin, (GPIO_PinState)0);
        m_state = EState::eDisabled;
    }

    Coil::EState Coil::getState()
    {
        return m_state;
    }
}
