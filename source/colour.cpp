#include <colour.h>

inline int Constrain(int value, int min, int max) {
    if (value > max)
        return max;
    else if (value < min)
        return min;
    else return value;
}

Colour::Colour(int red, int green, int blue) {
    r = red;
    g = green;
    b = blue;
    a = 1;
};

Colour::Colour(int red, int green, int blue, int alpha) {
    r = red;
    g = green;
    b = blue;
    a = alpha;
};

float * Colour::MapValues() {
    float values [4];

    values[0] = (float)Constrain(r, 0, 255) / 255.0f;
    values[1] = (float)Constrain(g, 0, 255) / 255.0f;
    values[2] = (float)Constrain(b, 0, 255) / 255.0f;
    values[3] = (float)Constrain(a, 0, 100) / 100.0f;
};