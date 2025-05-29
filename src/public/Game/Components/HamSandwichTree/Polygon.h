#include <vector>
#include <glm/glm.hpp>

class Polygon {
public:
    std::vector<glm::vec2> vertices;

    Polygon(const std::vector<glm::vec2>& verts) : vertices(verts) {}

    bool IsConvex() const;
    bool ContainsPoint(const glm::vec2& point) const;
};
