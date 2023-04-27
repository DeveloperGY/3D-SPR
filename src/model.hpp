#ifndef MODEL_HPP
#define MODEL_HPP

#include <rotmatrix.h>

#include <vector>
#include <string>
#include <fstream>
#include <sstream>

namespace sr
{
    class Model
    {
    private:
        std::vector<rm_vec4f> vertices;
        std::vector<int> indices;

        rm_vec4f pos;
        rm_vec4f rot;
        rm_vec4f scl;

    public:
        Model();
        Model(std::vector<rm_vec4f> v, std::vector<int> i);

        rm_mat4f model_matrix();

        void translate(rm_vec4f v);
        void rotate(rm_vec4f v);
        void scale(rm_vec4f v);

        std::vector<rm_vec4f> get_vertices();
        std::vector<int> get_indices();
        int load_obj(std::string filename);
    };
}

#endif