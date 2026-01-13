#include "kernel_types.h"

void storage_service(void *arg)
{
    message_t msg;

    while (1) {
        xQueueReceive(get_service_queue(SERVICE_STORAGE),
                      &msg,
                      portMAX_DELAY);
    }
}
