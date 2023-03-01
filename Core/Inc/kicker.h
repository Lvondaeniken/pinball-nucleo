#include <stdint.h>

namespace Pinball
{
    class Switch;
    class Coil;

    class Kicker
    {
    public:
        Kicker(char id, Switch* pSwitch, Coil* pCoil);
        ~Kicker() = default;
        void update();
        void enable();
        void disable();

    private:
        enum class EState
        {
            eIdle,
            eCoilEnabled,
            eWaitSwitchRelease,
        };
        const char* getName();
        void setPWM(uint32_t val);

        Switch *m_switch;
        Coil *m_coil;

        char m_name[3] = "kx";
        uint16_t m_coilEnabledPeriods = 0;
        EState m_state;
        bool m_enable;
    };

}
