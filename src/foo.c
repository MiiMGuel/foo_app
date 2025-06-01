#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <memory.h>

#include "core/main.h"

typedef struct foo_data {
    char** argv;
    int32_t argc;
} foo_data_t;

static void _foo_start(uintptr_t* app_data) {
    foo_data_t* foo = (foo_data_t*)app_data;

    printf("Hello, World!\n");
    printf("args: %d\n", foo->argc);

    for (int32_t i = 0; i < foo->argc; i++) {
        printf("\t- %s\n", foo->argv[i]);
    }
}

// close() code below start() code for easier 
// object management (construction and deconstruction)
static void _foo_close(uintptr_t* app_data) {
    foo_data_t* foo = (foo_data_t*)app_data;
}

static void _foo_run(uintptr_t* app_data) {
    foo_data_t* foo = (foo_data_t*)app_data;
}

app_info_t main_app(int argc, char* argv[]) {
    foo_data_t* data = (foo_data_t*)malloc(sizeof(foo_data_t));
    memset(data, 0, sizeof(foo_data_t));
    
    data->argc = argc;
    data->argv = argv;

    return (app_info_t){
        .app_data = (uintptr_t*)data,
        .start    = _foo_start,
        .run      = _foo_run,
        .close    = _foo_close
    };
}
