#include <MainWindow.h>

#include "../include/Renderer.hpp"

namespace Argo::Graphics {
void Renderer::render() {
    auto main_window = MainWindow::create();
    main_window->run();
}
}  // namespace Argo::Graphics
