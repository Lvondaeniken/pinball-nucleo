
#include <stdint.h>

namespace Pinball
{
    class Switch;
    class Coil;

    class Bumper
    {
    public:
        Bumper(uint8_t id, Switch* pSwitch, Coil* pCoil);
        ~Bumper() = default;
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

        Switch *m_switch;
        Coil *m_coil;

        char m_name[3] = "bx";
        uint16_t m_coilEnabledPeriods = 0;
        EState m_state;
        bool m_enable;
    };

}
