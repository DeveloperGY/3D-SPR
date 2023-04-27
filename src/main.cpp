#include "model.hpp"
#include "renderer.hpp"

#include <iostream>

int main(void)
{
    // std::vector<rm_vec4f> vertices = {
    //     rm_genVec4f( 1,  1,  1, 1),
    //     rm_genVec4f( 1,  1, -1, 1),
    //     rm_genVec4f( 1, -1,  1, 1),
    //     rm_genVec4f( 1, -1, -1, 1),
    //     rm_genVec4f(-1,  1,  1, 1),
    //     rm_genVec4f(-1,  1, -1, 1),
    //     rm_genVec4f(-1, -1,  1, 1),
    //     rm_genVec4f(-1, -1, -1, 1),
    // };

    // std::vector<int> indices = {
    //     0, 1, 3, // right
    //     0, 2, 3, // right
    //     4, 0, 2, // front
    //     4, 6, 2, // front
    //     5, 6, 4, // left
    //     5, 6, 7, // left
    //     7, 5, 1, // back
    //     3, 7, 1, // back
    //     7, 3, 6, // bottom
    //     5, 0, 1 // top
    // };

    // sr::Model m(vertices, indices);

    // m.scale(rm_genVec4f(10, 10, 10, 0));
    // m.translate(rm_genVec4f(20, 20, 0, 0));
    // m.rotate(rm_genVec4f(45, 45, 45, 0));

    sr::Model tetra;
    
    if(!tetra.load_obj("res/monkey.obj"))
    {
        return -1;
    }

    tetra.scale(rm_genVec4f(80, -80, 80, 1));
    tetra.translate(rm_genVec4f(256, 100, 0, 0));
    tetra.rotate(rm_genVec4f(0, 0, 15, 0));

    td_initialize(512, 200);

    while(getch(0) != 'q')
    {
        // m.rotate(rm_genVec4f(0.5, 0.5, 0.5, 0));
        // sr::render(m);
        tetra.rotate(rm_genVec4f(0, 1, 1, 0));
        sr::render(tetra);
        td_display();
    }

    td_terminate(0);

    return 0;
}