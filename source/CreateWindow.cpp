#include <windows.h>
#include <String.h>
#include <renderer.h>
#include <map>

std::map<char, int> Background = {std::make_pair('r', 255),std::make_pair('g', 255),std::make_pair('b', 255)};
void SetBG(int r, int g, int b) {
    Background['r'] = r;
    Background['g'] = g;
    Background['b'] = b;
}

void draw(Renderer* r) {
    r->Background(Background['r'], Background['g'], Background['b']);
}

Renderer* renderer;

LRESULT CALLBACK WindowHandler(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        case WM_PAINT:
            renderer->BeginDraw();

            draw(renderer);

            renderer->EndDraw();
        default:
            return DefWindowProcW(hWnd, msg, wp, lp);
    }
}

bool GenWindow() {
    bool success = true;
    bool returned = false;

    WNDCLASSW wc = {0};
    wc.hInstance = NULL;
    wc.hbrBackground = (HBRUSH) COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpszClassName = L"node_gui";
    wc.lpfnWndProc = WindowHandler;
    wc.style = CS_HREDRAW | CS_VREDRAW;

    if (!RegisterClassW(&wc))
        success = false;

    if (success) {
//        try {
            RECT WinSize = {0, 0, 720, 360};
            AdjustWindowRectEx(&WinSize, WS_OVERLAPPEDWINDOW, false, WS_EX_OVERLAPPEDWINDOW);

            HWND WinHandler = CreateWindowW(L"node_gui", L"Node GUI", WS_OVERLAPPEDWINDOW | WS_VISIBLE, NULL, NULL, WinSize.right - WinSize.left, WinSize.bottom - WinSize.top, NULL, NULL,
                          NULL, NULL);

            renderer = new Renderer();

            if (!renderer->Init(WinHandler)) {
                delete renderer;
                success = false;
            }

//        } catch (int e) {
//            e;
//            success = false;
//        }

        MSG msg = {0};

        while (GetMessage(&msg, NULL, NULL, NULL)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        delete renderer;
    }

    return success;
}