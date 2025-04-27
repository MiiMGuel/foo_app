#include <stdio.h>
#include <stdlib.h>

#include "main.h"

static app_info_t _main_app = { 0 };

static void _main_close(void) {
    _main_app.close(_main_app.app_data);
    if (_main_app.app_data) free(_main_app.app_data);
}

int main(int argc, char* argv[]) {
    _main_app = main_app(argc, argv);
    int close = (_main_app.close != NULL) ? atexit(_main_close) : 0;
    if (close != 0) 
        printf("\"atexit(_main_close)\" failed! the program can't close properly.\n");
    if (_main_app.start != NULL) 
        _main_app.start(_main_app.app_data);
    if (_main_app.run != NULL) 
        _main_app.run(_main_app.app_data);
    return 0;
}
