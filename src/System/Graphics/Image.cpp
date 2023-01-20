#pragma once

#define STB_IMAGE_IMPLEMENTATION

#include "stb_image.h"

#include "Image.hpp"

namespace Argo {
    namespace Utilities {
        static uint32_t BytesPerPixel(ImageFormat format) {
            switch (format) {
                case ImageFormat::RGBA:
                    return 4;
                case ImageFormat::RGBA32F:
                    return 16;
            }
            return 0;
        }
    }

    Image::Image(std::string_view path) : filepath(path) {
        int width, height, channels;
        uint8_t* data = nullptr;

        if (stbi_is_hdr(this->filepath.c_str()))
        {
            data = (uint8_t*)stbi_loadf(filepath.c_str(), &width, &height, &channels, 4);
            this->format = ImageFormat::RGBA32F;
        }
        else
        {
            data = stbi_load(filepath.c_str(), &width, &height, &channels, 4);
            this->format = ImageFormat::RGBA;
        }

        this->width = width;
        this->height = height;
    }

    Image::Image(uint32_t width, uint32_t height, ImageFormat format, const void *data) {}

    Image::~Image()
    {
        Release();
    }

    void Image::AllocateMemory(uint64_t size) {}

    void Image::Release() {}

    void Image::SetData(const void *data) {}

    void Image::Resize(uint32_t width, uint32_t height) {}

}
