#include "kernel_types.h"

void control_service(void *arg)
{
    message_t msg;

    while (1) {
        xQueueReceive(get_service_queue(SERVICE_CONTROL),
                      &msg,
                      portMAX_DELAY);
    }
}
