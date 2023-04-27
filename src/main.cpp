#include "model.hpp"
#include "renderer.hpp"

#include <iostream>

int main(void)
{
    sr::Model tetra;
    
    if(!tetra.load_obj("res/stair.obj"))
    {
        return -1;
    }

    tetra.scale(rm_genVec4f(20, -20, 20, 1));
    tetra.translate(rm_genVec4f(40, 24, 0, 0));
    tetra.rotate(rm_genVec4f(0, 0, 15, 0));

    td_initialize(80, 48);

    while(getch(0) != 'q')
    {
        tetra.rotate(rm_genVec4f(1, 1, 1, 0));
        sr::render(tetra);
        td_display();
    }

    td_terminate(0);

    return 0;
}