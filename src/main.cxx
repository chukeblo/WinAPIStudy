#include <windows.h>

#include "window_manager.h"

int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nShowCmd
) {
    WindowManager* window_manager;
    if (!window_manager->Prepare(hInstance, nShowCmd)) return -1;

    MSG message = {};
    BOOL ret;
    while ((ret = GetMessage(&message, nullptr, 0, 0)) != 0) {
        if (ret == -1) break;
        TranslateMessage(&message);
        DispatchMessage(&message);
    }

    return 0;
}