#include "service_manager.h"

/* Service entry prototypes */
extern void kernel_service(void *);
extern void sensor_service(void *);
extern void comm_service(void *);
extern void storage_service(void *);
extern void control_service(void *);

#define SERVICE_QUEUE_LEN 8

static service_t service_table[SERVICE_MAX] = {
    [SERVICE_KERNEL] = {
        .id = SERVICE_KERNEL,
        .priority = 5,
        .stack_size = 1024,
        .entry = kernel_service,
    },
    [SERVICE_SENSOR] = {
        .id = SERVICE_SENSOR,
        .priority = 4,
        .stack_size = 1024,
        .entry = sensor_service,
    },
    [SERVICE_COMM] = {
        .id = SERVICE_COMM,
        .priority = 3,
        .stack_size = 1024,
        .entry = comm_service,
    },
    [SERVICE_STORAGE] = {
        .id = SERVICE_STORAGE,
        .priority = 2,
        .stack_size = 1024,
        .entry = storage_service,
    },
    [SERVICE_CONTROL] = {
        .id = SERVICE_CONTROL,
        .priority = 4,
        .stack_size = 1024,
        .entry = control_service,
    }
};

void service_manager_init(void)
{
    for (int i = 0; i < SERVICE_MAX; i++) {
        service_table[i].queue =
            xQueueCreate(SERVICE_QUEUE_LEN, sizeof(message_t));

        xTaskCreate(service_table[i].entry,
                    "svc",
                    service_table[i].stack_size,
                    NULL,
                    service_table[i].priority,
                    &service_table[i].task);
    }
}

QueueHandle_t get_service_queue(service_id_t id)
{
    if (id >= SERVICE_MAX)
        return NULL;
    return service_table[id].queue;
}
