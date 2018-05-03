#include <stdlib.h>

#include <system/system_context.h>

SystemContext *getGlobalSystemContext() {
    if (!globalSystemContext) {
        if (createGlobalSystemContext() < 0) {
            return NULL;
        }
    }
    return globalSystemContext;
}
