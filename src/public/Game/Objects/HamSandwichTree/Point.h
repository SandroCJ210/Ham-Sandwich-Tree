#pragma once
#include <Core/Components/Render/RenderCubeComponent.h>
#include <Core/Objects/AObject.h>

class Point : public AObject {
public:
	Point(
		const std::string &_name, 
		AObject* _parent = nullptr, 
		ASceneController* _scene = nullptr
	);
	~Point() override = default;

private:
	RenderCubeComponent* renderComponent;

public :
	void SetColor(glm::vec3);
	RenderCubeComponent* GetRenderComponent() const { return  renderComponent; }
};

struct ProjectedPoint {
    float projection;
    glm::vec3 point;

    bool operator<(const ProjectedPoint& other) const {
        return projection < other.projection;
    }
};