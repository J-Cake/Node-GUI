#pragma once

#include <windows.h>
#include <d2d1.h>

#include <Colour.h>

class Renderer {
    ID2D1Factory* factory;
    ID2D1HwndRenderTarget* renderTarget;

//private:
//    Colour fill;

public:
    Renderer();
    ~Renderer();

    bool Init(HWND WinHandler);

    void BeginDraw() {
        renderTarget->BeginDraw();
    };

    void EndDraw() {
        renderTarget->EndDraw();
    };

    void Background(int r, int g, int b);
    void Rect(int x, int y, int w, int h);
    void Fill(int r, int g, int b);
    int Constrain(int value, int min, int max);
};