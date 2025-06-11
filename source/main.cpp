#include <wups.h>
#include <notifications/notifications.h>

#include <whb/log_udp.h>
#include <whb/log.h>

WUPS_PLUGIN_NAME("Plugin");
WUPS_PLUGIN_DESCRIPTION("Description");
WUPS_PLUGIN_VERSION("v1.0");
WUPS_PLUGIN_AUTHOR("Author");

WUPS_USE_STORAGE("plugin");

ON_APPLICATION_START()
{
    WHBLogUdpInit();
    NotificationModule_InitLibrary();

    WHBLogPrintf("Hello Aroma!");
    NotificationModule_AddInfoNotification("Hello Aroma!");
}

ON_APPLICATION_REQUESTS_EXIT()
{
    NotificationModule_AddInfoNotification("Bye Aroma!");
    WHBLogPrintf("Bye Aroma!");
    
    NotificationModule_DeInitLibrary();
    WHBLogUdpDeinit();
}