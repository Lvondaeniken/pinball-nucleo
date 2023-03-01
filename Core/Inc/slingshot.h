#include <stdint.h>

namespace Pinball
{
    class Switch;
    class Coil;

    class Slingshot
    {
    public:
        Slingshot(char id, Switch* pSwitch, Coil* pCoil);
        ~Slingshot() = default;
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

        Switch* m_switch;
        Coil* m_coil;

        char m_name[3] = "sx";
        uint16_t m_coilEnabledPeriods = 0;
        EState m_state;
        bool m_enable;
    };

}
