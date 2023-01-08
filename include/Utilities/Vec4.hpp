#ifndef ARGOCPP_VEC4_HPP
#define ARGOCPP_VEC4_HPP

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

#endif //ARGOCPP_VEC4_HPP
