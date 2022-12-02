/*
    by korenkonder
    GitHub/GitLab: korenkonder
*/

#include "inject.hpp"
#include "print.hpp"
#include <Windows.h>

static void inject_data(void* address, const void* data, size_t count) {
    DWORD old_protect;
    VirtualProtect(address, count, PAGE_EXECUTE_READWRITE, &old_protect);
    memmove(address, (const void*)data, count);
    VirtualProtect(address, count, old_protect, &old_protect);
}

static int32_t PV_DB_LYRIC_COUNTER_DATA = 1000;
static void* PV_DB_LYRIC_COUNTER_ADDRESS = (void*)0x00000001404B1CBFULL;

void inject_patches() {
    printf_console("Patching pv_db max lyrics count");
    inject_data(PV_DB_LYRIC_COUNTER_ADDRESS,
        &PV_DB_LYRIC_COUNTER_DATA, sizeof(PV_DB_LYRIC_COUNTER_DATA));
}
