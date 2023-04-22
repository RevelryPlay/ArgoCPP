#include "ViewDelegate.hpp"

ArgoMTKViewDelegate::ArgoMTKViewDelegate(MTL::Device *pDevice)
        : MTK::ViewDelegate(), _pRenderer(new Renderer(pDevice)) {
}

ArgoMTKViewDelegate::~ArgoMTKViewDelegate() {
    delete _pRenderer;
}

void ArgoMTKViewDelegate::drawInMTKView(MTK::View *pView) {
    _pRenderer->draw(pView);
}
