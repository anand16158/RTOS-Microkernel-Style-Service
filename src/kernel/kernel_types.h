#ifndef KERNEL_TYPES_H
#define KERNEL_TYPES_H

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

/* Message IDs */
typedef enum {
    MSG_INIT,
    MSG_START,
    MSG_STOP,
    MSG_DATA,
    MSG_TIMEOUT,
    MSG_ERROR
} msg_id_t;

/* Service IDs */
typedef enum {
    SERVICE_KERNEL = 0,
    SERVICE_SENSOR,
    SERVICE_COMM,
    SERVICE_STORAGE,
    SERVICE_CONTROL,
    SERVICE_MAX
} service_id_t;

/* IPC message */
typedef struct {
    msg_id_t id;
    service_id_t src;
    service_id_t dst;
    void *payload;
} message_t;

/* Service descriptor */
typedef struct {
    service_id_t id;
    TaskHandle_t task;
    QueueHandle_t queue;
    UBaseType_t priority;
    uint16_t stack_size;
    void (*entry)(void *);
} service_t;

#endif
