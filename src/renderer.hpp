#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <termDisplay.h>
#include <rotmatrix.h>

#include "model.hpp"
#include "camera.hpp"

namespace sr
{
    void render(sr::Model m, sr::Camera c);
}

#endif