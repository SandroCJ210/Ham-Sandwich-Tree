#pragma once

class Shader;

class AMaterial {
public:
    Shader* shader;
	AMaterial() = default;
    virtual ~AMaterial() = default;
};
