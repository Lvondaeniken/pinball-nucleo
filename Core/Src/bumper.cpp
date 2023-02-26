
#include "bumper.h"
#include "coil.h"
#include "switch.h"

namespace Pinball
{
    Bumper::Bumper(uint8_t id, Switch* pSwitch, Coil* pCoil)
        : m_switch(pSwitch)
        , m_coil(pCoil)
        , m_coilEnabledPeriods(0)
        , m_state(EState::eIdle)
    {
        m_name[1] = (char)id;
    }

    void Bumper::update()
    {
        switch (m_state)
        {
        case EState::eIdle:
        {
            if (m_switch->isSet())
            {
                m_state = EState::eCoilEnabled;
                m_coilEnabledPeriods = 5;
                m_coil->enable();
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
                m_state = EState::eWaitSwitchRelease;
            }
            break;
        }
        case EState::eWaitSwitchRelease:
        {
            if (!m_switch->isSet())
            {
                m_state = EState::eIdle;
            }
            break;
        }
        }
    }

    const char* Bumper::getName()
    {
        return m_name;
    }

}
