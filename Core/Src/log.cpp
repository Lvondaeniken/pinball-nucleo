#include "usart.h"
namespace Pinball
{

    const char pNewline[] = "\r\n";

    void send(const char* pText)
    {
        HAL_UART_Transmit(&huart2, (uint8_t*)pText, sizeof(pText), 10);
        HAL_UART_Transmit(&huart2, (uint8_t*)pNewline, sizeof(pNewline), 10);
    }

    char receive()
    {
        uint8_t cmd;
        if (HAL_UART_Receive(&huart2, &cmd, 1, 10) == HAL_OK)
            return static_cast<char>(cmd);
        else
            return '?';
    }
}
