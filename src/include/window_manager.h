#ifndef WINDOW_MANAGER_H_
#define WINDOW_MANAGER_H_

#include <windows.h>

class WindowManager {
public:
    static WindowManager* GetInstance();
    static void DestroyInstance();

private:
    WindowManager();
    ~WindowManager();

public:
    bool Prepare(HINSTANCE h_instance, int cmd_show);
    LRESULT OnWindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
private:
    ATOM InitializeApplication(HINSTANCE h_instance);

private:
    static WindowManager* instance_;
    HWND window_handle_;
    HINSTANCE application_instance_;
    HWND button_;
};

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

#endif // WINDOW_MANAGER_H_