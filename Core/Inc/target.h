#include <stdint.h>

namespace Pinball
{
    class Switch;

    class Target
    {
    public:
        Target(uint8_t id, Switch *pSwitch);
        ~Target() = default;

    private:
        enum class EState
        {
            eIdle,
            eWaitSwitchRelease,
        };
        void update();
        const char* getName();

        Switch *m_switch;
        char m_name[3] = "tx";
        EState m_state;
    };

}
