#include "message_router.h"
#include "service_manager.h"

#define ROUTER_QUEUE_LEN 16

static QueueHandle_t router_queue;

static void router_task(void *arg)
{
    message_t msg;

    while (1) {
        xQueueReceive(router_queue, &msg, portMAX_DELAY);

        QueueHandle_t q = get_service_queue(msg.dst);
        if (q) {
            xQueueSend(q, &msg, portMAX_DELAY);
        }
    }
}

void message_router_init(void)
{
    router_queue = xQueueCreate(ROUTER_QUEUE_LEN,
                                sizeof(message_t));

    xTaskCreate(router_task,
                "router",
                1024,
                NULL,
                6,
                NULL);
}

BaseType_t kernel_send_message(message_t *msg,
                               TickType_t timeout)
{
    return xQueueSend(router_queue, msg, timeout);
}

BaseType_t kernel_send_message_isr(message_t *msg,
                                   BaseType_t *woken)
{
    return xQueueSendFromISR(router_queue, msg, woken);
}
