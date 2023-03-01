

#include "slingshot.h"
#include "coil.h"
#include "log.h"
#include "switch.h"

namespace Pinball
{
    Slingshot::Slingshot(char id, Switch* pSwitch, Coil* pCoil)
        : m_switch(pSwitch)
        , m_coil(pCoil)
        , m_coilEnabledPeriods(0)
        , m_state(EState::eIdle)
        , m_enable(false)
    {
        m_name[1] = id;
    }

    void Slingshot::update()
    {
        switch (m_state)
        {
        case EState::eIdle:
        {
            if (m_switch->isSet())
            {
                send("slingshot");
                m_state = EState::eCoilEnabled;
                m_coilEnabledPeriods = 5;
                if (m_enable)
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

    const char* Slingshot::getName()
    {
        return m_name;
    }

    void Slingshot::enable()
    {
        m_enable = true;
    }

    void Slingshot::disable()
    {
        m_enable = false;
    }
}
