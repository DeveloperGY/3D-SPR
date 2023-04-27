#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <rotmatrix.h>
#include <cmath>

namespace sr
{
    class Camera
    {
    private:
        rm_vec4f position;
        rm_vec4f world_up;

        rm_vec4f rot;

    public:
        Camera();

        rm_mat4f view_matrix();

        void rotate(rm_vec4f rotate);
        // void translate(rm_vec4f translate);
    };
}

#endif