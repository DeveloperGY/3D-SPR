#include "renderer.hpp"

void sr::render(sr::Model m)
{
    std::vector<rm_vec4f> screen_vertices;

    for (auto v: m.get_vertices())
    {
        rm_vec4f point = rm_applyMatrix4f(v, m.model_matrix());

        screen_vertices.push_back(point);
    }

    if (m.get_indices().size() % 3 == 0)
    {
        for (int i=0; i<m.get_indices().size(); i+=3)
        {
            rm_vec4f p1 = screen_vertices.at(m.get_indices().at(i));
            rm_vec4f p2 = screen_vertices.at(m.get_indices().at(i+1));
            rm_vec4f p3 = screen_vertices.at(m.get_indices().at(i+2));

            td_drawLine(p1.v[0], p1.v[1], p3.v[0], p3.v[1], '.', TD_COLOR_CYAN, TD_COLOR_DEFAULT);
            td_drawLine(p3.v[0], p3.v[1], p2.v[0], p2.v[1], '.', TD_COLOR_CYAN, TD_COLOR_DEFAULT);
            td_drawLine(p2.v[0], p2.v[1], p1.v[0], p1.v[1], '.', TD_COLOR_CYAN, TD_COLOR_DEFAULT);
        }
    }

    for (auto v: screen_vertices)
    {
        td_drawPoint(v.v[0], v.v[1], '.', TD_COLOR_CYAN, TD_COLOR_DEFAULT);
    }
}