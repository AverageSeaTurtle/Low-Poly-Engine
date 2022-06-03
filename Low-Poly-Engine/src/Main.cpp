#include "Application.h"

#include "Vector3D.h"
#include "Node.h"

#include <iostream>

int main(void)
{
    Application App;

    if (!App.Init())
        return -1;

    Node A, B;
    A.position = Vector3D(1, 1, 1);
    B.position = Vector3D(10, 0, 3);

    A.AddChildNode(B);
    A.Update();

    std::cout << B.GetParentNode().position << std::endl;

    App.Loop();

    return 0;
}