#pragma once

#include "CommonIncludes.hpp"

namespace Argo {
    namespace Utilities {
        /**
         * Generic color that can be used throughout Argo
         */
        class CommonColor {
        public:
            float red = 1.0f;
            float green = 1.0f;
            float blue = 1.0f;
            float alpha = 1.0f;

            /**
             * Returns an Vec4 for compatibility with other libraries
             * @return Vec4
             */
            glm::vec4 ToVec4() const {
                return glm::vec4(
                        red,
                        green,
                        blue,
                        alpha
                );
            }
        };
    }
}
