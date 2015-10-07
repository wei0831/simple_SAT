#include "VectorMath.h"
#include <vector>

struct SAT_AABB
{
    SAT_AABB(float x, float y, float w)
    {
        float half_w = w * 0.5f;
        minBound = { x - half_w, y - half_w };
        maxBound = { x + half_w, y + half_w };
    }
    Vec2 getCenter() const { return 0.5f * (minBound + maxBound); }

    Vec2 minBound;
    Vec2 maxBound;
};

// Must add points in clockwise direction
struct SAT_POLY
{
    SAT_POLY(){}

    void AddPoints(float x, float y)
    {
        Vec2 toAdd = Vec2(x, y);
        vertices.push_back(toAdd);
    }

    bool RecomputeFaces()
    {
        if (!isValid()) return false;

        faces.clear();
        for (unsigned int i = 0; i < vertices.size(); i++)
            faces.push_back(
            Vec2DNormalVector(vertices[i],
            vertices[(i + 1) % vertices.size()])
            );

        return true;
    }

    bool isValid()
    {
        return (vertices.size() > 2);
    }

    Vec2 getFarestPoint(const Vec2& dir) const
    {
        float resultProjection = -FLT_MAX;
        Vec2 resultVertex;

        for (unsigned int i = 0; i < vertices.size(); i++)
        {
            Vec2 v = vertices[i];
            float proj = Vec2DDot(v, dir);

            if (proj > resultProjection)
            {
                resultVertex = v;
                resultProjection = proj;
            }
        }

        return resultVertex;
    }

    std::vector<Vec2> vertices;
    std::vector<Vec2> faces;
};

inline std::ostream& operator<<(std::ostream& os, const SAT_POLY& p)
{
    os << "Vertex Count: " << p.vertices.size() << std::endl;
    for (unsigned int i = 0; i < p.vertices.size(); i++)
    {
        os << p.vertices[i];
    }
    os << std::endl;
    return os;
}

float FindLeastPenetration(const SAT_POLY&, const SAT_POLY&);
float LeastPenetrationHelper(const SAT_POLY&, const SAT_POLY&, const Vec2&);
bool SAT(const SAT_POLY&, const SAT_POLY&);
