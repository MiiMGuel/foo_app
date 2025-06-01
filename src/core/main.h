#ifndef MAIN_H
#define MAIN_H

#include <stdint.h>

typedef struct app_info {
    void (*start)(uintptr_t* app_data);
    void (*run)(uintptr_t* app_data);
    void (*close)(uintptr_t* app_data);
    // will be freed after _main_app.close() is called
    uintptr_t* app_data;
} app_info_t;

#endif // MAIN_H