#ifndef ARGOCPP_COLOR_CONVERTER_H
#define ARGOCPP_COLOR_CONVERTER_H

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
     * Returns an ImVec4 for compatibility with Dear ImGui
     * @return ImVec4
     */
    ImVec4 ToImVec4() const {
        return ImVec4(
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

#endif //ARGOCPP_COLOR_CONVERTER_H
