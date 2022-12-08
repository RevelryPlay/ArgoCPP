#ifndef ARGOCPP_COLOR_CONVERTER_H
#define ARGOCPP_COLOR_CONVERTER_H

#include "imgui.h"

ImVec4 ConvertColor(ImVec4 rgba) {
    return {rgba.x / 255, rgba.y / 255, rgba.z / 255, rgba.w};
}

ImVec4 ConvertColor(int hex) {
    ImVec4 rgba = ImVec4();

    rgba.x = ((hex >> 16) & 0xFF) / 255.0;
    rgba.y = ((hex >> 8) & 0xFF) / 255.0;
    rgba.z = ((hex) & 0xFF) / 255.0;
    rgba.w = 1;

    return rgba;
}

#endif //ARGOCPP_COLOR_CONVERTER_H
