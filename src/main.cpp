#include "model.hpp"
#include "camera.hpp"
#include "renderer.hpp"

#include <iostream>

int main(void)
{
    sr::Model tetra;
    
    if(!tetra.load_obj("res/pyra.obj"))
    {
        return -1;
    }

    tetra.scale(rm_genVec4f(20, -20, 20, 1));
    tetra.translate(rm_genVec4f(40, 20, -5, 0));
    tetra.rotate(rm_genVec4f(5, 10, 15, 0));


    sr::Camera cam;

    td_initialize(80, 48);

    while(getch(0) != 'q')
    {
        cam.rotate(rm_genVec4f(0, 1, 0, 1));
        tetra.rotate(rm_genVec4f(1, 1, 1, 1));
        sr::render(tetra, cam);
        td_display();
    }

    td_terminate(1);

    return 0;
}