
#include <stdint.h>

namespace Pinball
{
    class Switch;
    class Coil;

    class Ballshooter
    {
    public:
        Ballshooter(Switch* pSwitch, Coil* pBallshooterCoil, Coil* pMagazineCoil);
        ~Ballshooter() = default;
        void update();
        void enable();
        void disable();

    private:
        enum class EState
        {
            eIdle,
            eCoilEnabled,
            eWaitSwitchRelease,
            eWaitRefill
        };
        const char* getName();

        Switch* m_switch;
        Coil* m_ballshooterCoil;
        Coil* m_magazineCoil;

        char m_name[3] = "bs";
        uint16_t m_coilEnabledPeriods = 0;
        EState m_state;
        bool m_enable;
    };

}
