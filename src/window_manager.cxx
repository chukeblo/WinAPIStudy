#include "window_manager.h"

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
    return true;
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
    switch (message) {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    }
    return DefWindowProc(hwnd, message, wParam, lParam);
}