#ifndef RENDERER_HPP
#define RENDERER_HPP

namespace Argo::Graphics {

struct Renderer {
    static int render();

private:
    static void glfwErrorCallback(int error, const char* description);
};

}

#endif //RENDERER_HPP
