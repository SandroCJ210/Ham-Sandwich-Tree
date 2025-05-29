#include <Game/Components/HamSandwichTree/Polygon.h>

bool Polygon::ContainsPoint(const glm::vec2& point) const
{
    int n = vertices.size();
    float lastCross = 0;

    for (int i = 0; i < n; ++i) {
        glm::vec2 a = vertices[i];
        glm::vec2 b = vertices[(i + 1) % n];
        glm::vec2 edge = b - a;
        glm::vec2 toPoint = point - a;

        float cross = edge.x * toPoint.y - edge.y * toPoint.x;

        if (i == 0)
            lastCross = cross;
        else if (cross * lastCross < 0) 
            return false; 
    }

    return true;
}

bool Polygon::IsConvex() const 
{
    int n = vertices.size();
    if (n < 3) return false;  

    float lastCross = 0;
    for (int i = 0; i < n; ++i) {
        glm::vec2 A = vertices[i];
        glm::vec2 B = vertices[(i + 1) % n];
        glm::vec2 C = vertices[(i + 2) % n];

        glm::vec2 AB = B - A;
        glm::vec2 BC = C - B;

        float cross = AB.x * BC.y - AB.y * BC.x;

        if (i == 0)
            lastCross = cross;
        else if (cross * lastCross < 0)
            return false;  
    }

    return true;
}
