#include "camera.hpp"

sr::Camera::Camera()
{
    this->position = rm_genVec4f(0, 0, 0, 1);
    this->world_up = rm_genVec4f(0, 1, 0, 1);
    this->rot = rm_genVec4f(0, -90, 0, 1);

    return;
}

rm_mat4f sr::Camera::view_matrix()
{
    // Handle rotation

    // Calculate Camera Axes

    float rad = M_PI / 180.0f;

    float pitch = this->rot.v[2];
    float yaw = this->rot.v[1];

    rm_vec4f direction = rm_normalize(rm_genVec4f(
        std::cos(yaw * rad) * std::cos(pitch * rad),
        std::sin(pitch * rad),
        std::sin(yaw * rad) * std::cos(pitch * rad),
        1
    ));

    rm_vec4f right = rm_normalize(rm_crossProduct(this->world_up, direction, 1));
    rm_vec4f up = rm_crossProduct(direction, right, 1);


    // Generate Matrix

    rm_mat4f m = {{
            right.v[0],     right.v[1],     right.v[2], 0,
               up.v[0],        up.v[1],        up.v[2], 0,
        direction.v[0], direction.v[1], direction.v[2], 0,
                     0,              0,              0, 1
    }};

    rm_mat4f look_at = rm_multiplyMatrix4f(
        m,
        rm_genTranslation4f(
            -this->position.v[0],
            -this->position.v[1],
            -this->position.v[2]
        )
    );

    // return look_at;
    return rm_genIdentity4f();
}

void sr::Camera::rotate(rm_vec4f rotate)
{
    this->rot.v[0] += rotate.v[0];
    this->rot.v[1] += rotate.v[1];
    this->rot.v[2] += rotate.v[2];

    return;
}

// void sr::Camera::translate(rm_vec4f translate)
// {
//     this->position.v[0] += translate.v[0];
//     this->position.v[1] += translate.v[1];
//     this->position.v[2] += translate.v[2];
//     return;
// }