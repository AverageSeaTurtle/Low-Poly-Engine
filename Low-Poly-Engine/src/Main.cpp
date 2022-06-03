#include "Application.h"

#include "Vector3D.h"

#include <iostream>

int main(void)
{
    Application App;

    if (!App.Init())
        return -1;

    //App.Loop();

    return 0;
}