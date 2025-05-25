#pragma once
#include <Core/Components/Render/RenderCubeComponent.h>
#include <Core/Objects/AObject.h>

class Point : public AObject {
public:
	Point(const std::string &_name, AObject* _parent, ASceneController* _scene);
	~Point() override = default;

private:
	RenderCubeComponent* renderComponent;

public :
	RenderCubeComponent* GetRenderComponent() const { return  renderComponent; }
};