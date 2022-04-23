#include <windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    }
    return DefWindowProc(hwnd, message, wParam, lParam);
}

int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nShowCmd
) {
    WNDCLASSEX wcex;
    ZeroMemory((LPVOID)&wcex, sizeof(WNDCLASSEX));

    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = 0;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = nullptr;
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_BACKGROUND + 1);
    wcex.lpszMenuName = nullptr;
    wcex.lpszClassName = "WindowManager";
    wcex.hIconSm = nullptr;

    RegisterClassEx(&wcex);

    HWND hWnd = CreateWindow(
        "WindowManager",
        "WinAPITest",
        WS_OVERLAPPEDWINDOW,
        0, 0,
        400, 300,
        nullptr, nullptr,
        hInstance,
        nullptr
    );
    if (!hWnd) return 0;

    ShowWindow(hWnd, SW_SHOW);

    MSG message = {};
    while (GetMessage(&message, nullptr, 0, 0) == 1) {
        TranslateMessage(&message);
        DispatchMessage(&message);
    }

    return 0;
}