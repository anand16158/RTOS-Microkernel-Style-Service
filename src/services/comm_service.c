#include "kernel_types.h"

void comm_service(void *arg)
{
    message_t msg;

    while (1) {
        xQueueReceive(get_service_queue(SERVICE_COMM),
                      &msg,
                      portMAX_DELAY);
    }
}
