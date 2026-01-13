#include "kernel_types.h"

void sensor_service(void *arg)
{
    message_t msg;

    while (1) {
        xQueueReceive(get_service_queue(SERVICE_SENSOR),
                      &msg,
                      portMAX_DELAY);

        if (msg.id == MSG_INIT) {
            /* sensor init */
        }
    }
}
