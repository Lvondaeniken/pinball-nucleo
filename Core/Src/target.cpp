

#include "target.h"
#include "log.h"
#include "switch.h"

namespace Pinball
{
    Target::Target(uint8_t id, Switch* pSwitch)
        : m_switch(pSwitch)
        , m_state(EState::eIdle)
    {
        m_name[1] = (char)id;
    }

    void Target::update()
    {
        switch (m_state)
        {
        case EState::eIdle:
        {
            if (m_switch->isSet())
            {
                send(m_name);
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

    const char* Target::getName()
    {
        return m_name;
    }

}
