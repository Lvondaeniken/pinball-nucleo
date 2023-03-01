
#include "kicker.h"
#include "coil.h"
#include "log.h"
#include "switch.h"

namespace Pinball
{
    Kicker::Kicker(char id, Switch* pSwitch, Coil* pCoil)
        : m_switch(pSwitch)
        , m_coil(pCoil)
        , m_coilEnabledPeriods(0)
        , m_state(EState::eIdle)
        , m_enable(false)
    {
        m_name[1] = id;
    }

    void Kicker::update()
    {
        switch (m_state)
        {
        case EState::eIdle:
        {
            if (m_switch->isSet())
            {
                send("kicker");
                m_state = EState::eCoilEnabled;
                m_coilEnabledPeriods = 5;
                if (m_enable)
                {
                    m_coil->enable();
                    setPWM(1000);
                }
            }
            break;
        }
        case EState::eCoilEnabled:
        {
            if (m_coilEnabledPeriods > 0)
            {
                m_coilEnabledPeriods--;
            }
            else
            {
                m_coil->disable();
                if (m_enable)
                    setPWM(500);
                m_state = EState::eWaitSwitchRelease;
            }
            break;
        }
        case EState::eWaitSwitchRelease:
        {
            if (!m_switch->isSet())
            {
                m_state = EState::eIdle;
                setPWM(0);
            }
            break;
        }
        }
    }

    const char* Kicker::getName()
    {
        return m_name;
    }

    void Kicker::setPWM(uint32_t val)
    {
        if (m_name[1] == 'r')
        {
            TIM1->CCR2 = val;
        }
        else if (m_name[1] == 'l')
        {
            TIM1->CCR1 = val;
        }
        else
        {
        }
    }
    void Kicker::enable()
    {
        m_enable = true;
    }

    void Kicker::disable()
    {
        m_enable = false;
    }

}
