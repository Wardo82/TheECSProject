#pragma once

#include "Component.h"
#include "Vector3D.h"

#define VECTOR_DATA_TYPE float

class Transform: public Component {
public:
    Transform() = default;
    
    Transform(Vector3D<VECTOR_DATA_TYPE>& pos) {
        position = pos;
        scale.ones();
    }
    
    Transform(Vector3D<VECTOR_DATA_TYPE>& pos, Vector3D<VECTOR_DATA_TYPE>& pscale) {
        position = pos;
        scale = pscale;
    }
    
    virtual ~ Transform() {}
    
    bool init() { return true; };
    void draw() {};
    void update() {};
    
    Vector3D<VECTOR_DATA_TYPE> position = Vector3D<VECTOR_DATA_TYPE>();
    Vector3D<VECTOR_DATA_TYPE> scale = Vector3D<VECTOR_DATA_TYPE>(1, 1, 1);
    VECTOR_DATA_TYPE rotation = 0.0f;
private:
};
