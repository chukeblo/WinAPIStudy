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
    HWND GetButton();
    void SetButton(HWND button);
private:
    ATOM InitializeApplication(HINSTANCE h_instance);

public:
    HINSTANCE h_instance_;
private:
    static WindowManager* instance_;
    HWND window_handle_;
    HWND button_;
};

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

#endif // WINDOW_MANAGER_H_