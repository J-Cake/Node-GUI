#include "renderer.h"

Renderer::Renderer() {
    factory = NULL;
    renderTarget = NULL;
}

Renderer::~Renderer() {
    if (factory)
        factory->Release();
    if (renderTarget)
        renderTarget->Release();
}

bool Renderer::Init(HWND WinHandler) {
    HRESULT res = D2D1CreateFactory(D2D1_FACTORY_TYPE::D2D1_FACTORY_TYPE_SINGLE_THREADED, &factory);
    if (res != S_OK)
        return false;

    RECT WinSize;
    GetClientRect(WinHandler, &WinSize);

    res = factory->CreateHwndRenderTarget(
            D2D1::RenderTargetProperties(),
            D2D1::HwndRenderTargetProperties(WinHandler, D2D1::SizeU(WinSize.right, WinSize.bottom)),
            &renderTarget);

    if (res != S_OK)
        return false;
    return true;
}