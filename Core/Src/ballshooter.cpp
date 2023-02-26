
#include "ballshooter.h"
#include "coil.h"
#include "switch.h"
#include "log.h"

namespace Pinball
{
    Ballshooter::Ballshooter(Switch* pSwitch, Coil* pBallshooterCoil, Coil* pMagazineCoil)
        : m_switch(pSwitch)
        , m_ballshooterCoil(pBallshooterCoil)
        , m_magazineCoil(pMagazineCoil)
        , m_coilEnabledPeriods(0)
        , m_state(EState::eIdle)
    {
    }

    void Ballshooter::update()
    {
        switch (m_state)
        {
        case EState::eIdle:
        {
            if (m_switch->isSet())
            {
                m_state = EState::eCoilEnabled;
                m_coilEnabledPeriods = 5;
                m_ballshooterCoil->enable();
                send("bs");
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
                m_ballshooterCoil->disable();
                m_state = EState::eWaitSwitchRelease;
            }
            break;
        }
        case EState::eWaitSwitchRelease:
        {
            if (!m_switch->isSet())
            {
                m_state = EState::eWaitRefill;
                m_magazineCoil->enable();
                m_coilEnabledPeriods = 5;
            }
            break;
        }
        case EState::eWaitRefill:
        {
            if (m_coilEnabledPeriods > 0)
            {
                m_coilEnabledPeriods--;
            }
            else
            {
                m_magazineCoil->disable();
                m_state = EState::eIdle;
            }
          break;
        }
        }
    }

    const char* Ballshooter::getName()
    {
        return m_name;
    }

}
