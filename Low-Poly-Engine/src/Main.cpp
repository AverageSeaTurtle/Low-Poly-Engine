#include "Application.h"

#include "Vector3D.h"
#include "Node.h"

#include <iostream>

int main(void)
{
    Application App;
    if (!App.Init())
        return -1;

    App.backgroud_color = COLOR::RGB_f(0.14, 0.17, 0.23, 1.0);

    App.Loop();

    return 0;
}