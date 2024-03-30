#ifndef COMMONCOLOR_HPP
#define COMMONCOLOR_HPP

#include "Vec4.hpp"
#include <iostream>

using namespace std;

namespace Argo::Core {
    /**
     * Generic color that can be used throughout Argo
     */
    struct CommonColor {
        float red = 1.0F;
        float green = 1.0F;
        float blue = 1.0F;
        float alpha = 1.0F;

        /**
         * Returns an Vec4 for compatibility with other libraries
         * @return Vec4
         */
        [[nodiscard]] Vec4 ToVec4() const { return Vec4({red, green, blue, alpha}); }


        /**
         * Returns a hexadecimal string for the current CommonColor
         * @return string
         */
        [[nodiscard]] auto ToHex() const {
            string hexRet;

            hexRet += decimalToHex(red * 255);
            hexRet += decimalToHex(green * 255);
            hexRet += decimalToHex(blue * 255);
            hexRet += decimalToHex(alpha * 255);

            return hexRet;
        }

    private:
        static string decimalToHex(int decimal);
    };
}

#endif //COMMONCOLOR_HPP
