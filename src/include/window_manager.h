#ifndef WINDOW_MANAGER_H_
#define WINDOW_MANAGER_H_

#include <windows.h>

class WindowManager {
public:
    WindowManager();
    ~WindowManager();

public:
    bool Prepare(HINSTANCE h_instance, int cmd_show);
private:
    ATOM InitializeApplication(HINSTANCE h_instance);

private:
    HWND window_handle_;
};

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

#endif // WINDOW_MANAGER_H_