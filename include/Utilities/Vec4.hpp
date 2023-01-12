#pragma once
struct Vec4 {
public:
    float x;
    float y;
    float z;
    float w;

    Vec4(float x, float y, float z, float w) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
    }
};
