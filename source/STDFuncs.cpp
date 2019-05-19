#include <renderer.h>

void Renderer::Background(int r, int g, int b) {
    renderTarget->Clear(D2D1::ColorF((float)r/255.0f, (float)g/255.0f, (float)b/255.0f));
}

void Renderer::Rect(int x, int y, int w, int h) {
//    renderTarget->DrawRectangle(D2D1::RectF(
//
//            ));
}

void Renderer::Fill(int r, int g, int b) {

}

int Renderer::Constrain(int value, int min, int max) {
    if (value > max)
        return max;
    else if (value < min)
        return min;
    else return value;
}