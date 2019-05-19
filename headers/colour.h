class Colour {
private:
    int r, g, b, a;
public:
    Colour(int r, int g, int b, int a);
    Colour(int r, int g, int b);

    float * MapValues();
};