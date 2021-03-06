#include "window_manager.h"

static const int kButtonId = 100;

WindowManager* WindowManager::instance_ = nullptr;

WindowManager* WindowManager::GetInstance() {
    if (!instance_) {
        instance_ = new WindowManager();
    }
    return instance_;
}

void WindowManager::DestroyInstance() {
    if (!instance_) return;
    delete instance_;
    instance_ = nullptr;
}

WindowManager::WindowManager()
{
}

WindowManager::~WindowManager()
{
}

bool WindowManager::Prepare(HINSTANCE h_instance, int cmd_show) {
    if (!InitializeApplication(h_instance)) return false;

    HWND hWnd = CreateWindow(
        "WindowManager",
        "WinAPITest",
        WS_OVERLAPPEDWINDOW,
        0, 0,
        400, 300,
        nullptr, nullptr,
        h_instance,
        nullptr
    );
    if (!hWnd) return false;

    ShowWindow(hWnd, cmd_show);
    UpdateWindow(hWnd);
    this->window_handle_ = hWnd;
    this->application_instance_ = h_instance;
    return true;
}

LRESULT WindowManager::OnWindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
    case WM_CREATE:
        this->button_ = CreateWindowEx(
            0, TEXT("BUTTON"), TEXT("push!"),
            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            10, 100, 50, 30,
            hwnd, (HMENU)kButtonId, this->application_instance_, nullptr
        );
        break;
    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case kButtonId:
            MessageBox(hwnd, "button pressed!", "notification", MB_OK);
            break;
        }
        break;
    case WM_CLOSE:
        DestroyWindow(button_);
        DestroyWindow(hwnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, message, wParam, lParam);
    }
    return 0;
}

ATOM WindowManager::InitializeApplication(HINSTANCE h_instance) {
    WNDCLASSEX wcex;
    ZeroMemory((LPVOID)&wcex, sizeof(WNDCLASSEX));

    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = 0;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.hInstance = h_instance;
    wcex.hIcon = nullptr;
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_BACKGROUND + 1);
    wcex.lpszMenuName = nullptr;
    wcex.lpszClassName = "WindowManager";
    wcex.hIconSm = nullptr;

    return (RegisterClassEx(&wcex));
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    return WindowManager::GetInstance()->OnWindowProcedure(hwnd, message, wParam, lParam);
}