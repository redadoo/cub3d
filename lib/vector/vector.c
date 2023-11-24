#include "vector.h"

vector2 vector2_lerp(vector2 a, vector2 b, float t)
{
    vector2 res;

	if (t < 0) t = 0;
    else if (t > 1) t = 1;

    res.x = a.x + (b.x - a.x) * t;
    res.y = a.y + (b.y - a.y) * t;
    return res;
}

vector2 vector2_lerp_unclamped(vector2 a, vector2 b, float t)
{
    vector2 res;

    res.x = a.x + (b.x - a.x) * t;
    res.y = a.y + (b.y - a.y) * t;
    return res;
}