/*
    by korenkonder
    GitHub/GitLab: korenkonder
*/

#include "print.hpp"
#include <stdarg.h>
#include <stdio.h>

HANDLE console_window_handle;

void printf_console(const char* fmt, ...) {
    if (!console_window_handle)
        return;

    printf("[OpenLyricLimit] ");
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
    printf("\n");
}
