#include "Collision.h"

float FindLeastPenetration(const SAT_POLY& A, const SAT_POLY& B)
{
    float bestDistance = -FLT_MAX;

    for (unsigned int i = 0; i < A.faces.size(); i++)
    {
        Vec2 vf = A.faces[i];
        float d = LeastPenetrationHelper(A, B, vf);
        if (d > bestDistance)
            bestDistance = d;
    }

    return bestDistance;
}

float LeastPenetrationHelper(const SAT_POLY& A, const SAT_POLY& B, const Vec2& normalVec)
{
    // A Max Bound
    Vec2 v1 = A.getFarestPoint(normalVec);
    float d1 = Vec2DDot(v1, normalVec);

    // B Min Bound
    Vec2 v2 = B.getFarestPoint(-normalVec);
    float d2 = Vec2DDot(v2, normalVec);

    return d2 - d1;
}
bool SAT(const SAT_POLY& A, const SAT_POLY& B)
{
    if (FindLeastPenetration(A, B) > 0.0f)
        return false;

    if (FindLeastPenetration(B, A) > 0.0f)
        return false;

    return true;
}
