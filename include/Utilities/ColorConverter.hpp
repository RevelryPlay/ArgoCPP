#ifndef ARGOCPP_COLOR_CONVERTER_HPP
#define ARGOCPP_COLOR_CONVERTER_HPP

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

/**
 * Generic color that can be used throughout Argo
 */
class CommonColor {
public:
    float red;
    float green;
    float blue;
    float alpha = 1.0f;

    /**
     * Returns an Vec4 for compatibility with other libraries
     * @return Vec4
     */
    Vec4 ToVec4() const {
        return Vec4(
                red,
                green,
                blue,
                alpha
        );
    }
};

/**
 * Creates a CommonColor from an RGBA object
 *
 * @param rgba - { red, green, blue, alpha }; red, green, blue values are between 0 and 255; alpha is a float between 0 and 1
 * @return CommonColor
 */
CommonColor ConvertColor(CommonColor rgba) {
    return {rgba.red / 255, rgba.green / 255, rgba.blue / 255, rgba.alpha};
}

/**
 * Creates a CommonColor from a hexadecimal value with alpha
 * @param hex - 0xRRGGBBAA
 * @return CommonColor
 */
CommonColor ConvertColor(unsigned int hex) {
    CommonColor rgba = CommonColor();

    rgba.red = ((hex >> 24) & 0xFF) / 255.0;
    rgba.green = ((hex >> 16) & 0xFF) / 255.0;
    rgba.blue = ((hex >> 8) & 0xFF) / 255.0;
    rgba.alpha = ((hex) & 0xFF) / 255.0;

    return rgba;
}

#endif //ARGOCPP_COLOR_CONVERTER_HPP
