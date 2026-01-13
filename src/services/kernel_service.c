#include "kernel_types.h"
#include "message_router.h"

void kernel_service(void *arg)
{
    message_t msg;

    /* Send INIT to all services */
    for (int i = 1; i < SERVICE_MAX; i++) {
        msg.id = MSG_INIT;
        msg.src = SERVICE_KERNEL;
        msg.dst = i;
        msg.payload = NULL;
        kernel_send_message(&msg, portMAX_DELAY);
    }

    while (1) {
        vTaskDelay(portMAX_DELAY);
    }
}
