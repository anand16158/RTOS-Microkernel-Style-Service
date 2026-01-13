#ifndef MESSAGE_ROUTER_H
#define MESSAGE_ROUTER_H

#include "kernel_types.h"

BaseType_t kernel_send_message(message_t *msg,
                               TickType_t timeout);

BaseType_t kernel_send_message_isr(message_t *msg,
                                   BaseType_t *woken);

void message_router_init(void);

#endif
