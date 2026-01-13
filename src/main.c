#include "service_manager.h"
#include "message_router.h"

int main(void)
{
    message_router_init();
    service_manager_init();

    vTaskStartScheduler();

    while (1);
}
