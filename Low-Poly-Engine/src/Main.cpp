#include "Application.h"

int main(void)
{
    Application App(640, 400, "Low-Poly Sandbox");
    if (!App.Init())
        return -1;

    App.SetBackgroundColor(COLOR::RGB_f(0.14, 0.17, 0.23, 1.0));

    App.Loop();

    return 0;
}