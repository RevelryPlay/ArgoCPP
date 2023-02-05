#pragma once

#include <string>;
#include <GLFW/glfw3.h>

namespace Argo {
    enum class ImageFormat {
        None = 0,
        RGBA,
        RGBA32F
    };

    class Image {
    public:
        Image(std::string_view path);

        Image(uint32_t width, uint32_t height, ImageFormat format, const void *data);

        ~Image();

        unsigned char *imageData;
        int nrChannels;

        void Resize(uint32_t width, uint32_t height);

        void SetData(const void *data);

        uint32_t GetWidth() const { return width; }

        uint32_t GetHeight() const { return height; }

    private:
        uint32_t width = 0, height = 0;
        ImageFormat format = ImageFormat::None;
        std::string filepath;

        void AllocateMemory(uint64_t size);

        void Release();
    };
}

