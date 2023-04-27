#include "model.hpp"

sr::Model::Model(std::vector<rm_vec4f> v, std::vector<int> i)
{
    this->vertices = v;
    this->indices = i;

    this->pos = rm_genVec4f(0, 0, 0, 1);
    this->rot = rm_genVec4f(0, 0, 0, 1);
    this->scl = rm_genVec4f(1, 1, 1, 1);

    return;
}

sr::Model::Model()
{
    this->pos = rm_genVec4f(0, 0, 0, 1);
    this->rot = rm_genVec4f(0, 0, 0, 1);
    this->scl = rm_genVec4f(1, 1, 1, 1);

    return;
}

rm_mat4f sr::Model::model_matrix()
{
    rm_mat4f m = rm_genIdentity4f();

    rm_mat4f rotx = rm_genRotationX4f(this->rot.v[0]);
    rm_mat4f roty = rm_genRotationY4f(this->rot.v[1]);
    rm_mat4f rotz = rm_genRotationZ4f(this->rot.v[2]);

    rm_mat4f translation = rm_genTranslation4f(
        this->pos.v[0],
        this->pos.v[1],
        this->pos.v[2]
    );

    rm_mat4f rotation = rm_multiplyMatrix4f(
        rm_multiplyMatrix4f(rotz, roty),
        rotx
    );

    rm_mat4f scale = rm_genScale4f(
        this->scl.v[0],
        this->scl.v[1],
        this->scl.v[2]
    );

    m = rm_multiplyMatrix4f(m, translation);
    m = rm_multiplyMatrix4f(m, rotation);
    m = rm_multiplyMatrix4f(m, scale);

    return m;
}

void sr::Model::translate(rm_vec4f v)
{
    this->pos.v[0] += v.v[0];
    this->pos.v[1] += v.v[1];
    this->pos.v[2] += v.v[2];
    return;
}

void sr::Model::rotate(rm_vec4f v)
{
    this->rot.v[0] += v.v[0];
    this->rot.v[1] += v.v[1];
    this->rot.v[2] += v.v[2];
    return;
}

void sr::Model::scale(rm_vec4f v)
{
    this->scl.v[0] += v.v[0];
    this->scl.v[1] += v.v[1];
    this->scl.v[2] += v.v[2];
    return;
}

std::vector<rm_vec4f> sr::Model::get_vertices()
{
    return this->vertices;
}


std::vector<int> sr::Model::get_indices()
{
    return this->indices;
}

int sr::Model::load_obj(std::string filename)
{
    std::ifstream file;

    file.open(filename, std::ifstream::in);

    if(!file.is_open())
    {
        return 0;
    }


    // read file
    std::string line;

    std::vector<rm_vec4f> l_vertices;
    std::vector<int> l_indices;

    while(std::getline(file, line))
    {
        if (line.substr(0, 2) == "v ")
        {
            std::istringstream s(line.substr(2));
            rm_vec4f vertex = rm_genVec4f(0, 0, 0, 1);
            s >> vertex.v[0] >> vertex.v[1] >> vertex.v[2];
            vertex.v[3] = 1;
            l_vertices.push_back(vertex);
        }
        else if (line.substr(0, 2) == "f ")
        {
            std::istringstream s(line.substr(2));
            int index[3] = {0, 0, 0};
            s >> index[0] >> index[1] >> index[2];

            l_indices.push_back(index[0] - 1);
            l_indices.push_back(index[1] - 1);
            l_indices.push_back(index[2] - 1);
        }
    }


    file.close();

    this->vertices.clear();
    this->indices.clear();

    for (auto v: l_vertices)
    {
        this->vertices.push_back(v);
    }

    for (auto i: l_indices)
    {
        this->indices.push_back(i);
    }

    return 1;
}