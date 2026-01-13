#ifndef SERVICE_MANAGER_H
#define SERVICE_MANAGER_H

#include "kernel_types.h"

void service_manager_init(void);
QueueHandle_t get_service_queue(service_id_t id);

#endif
