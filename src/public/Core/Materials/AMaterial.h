#pragma once

class Shader;

class AMaterial {
public:
    Shader* shader = nullptr;
	AMaterial() = default;
    virtual ~AMaterial() = default;
};
