#pragma once
#include "MacCommonIncludes.hpp"

#include "Renderer.hpp"

class ArgoMTKViewDelegate : public MTK::ViewDelegate {
public:
    ArgoMTKViewDelegate(MTL::Device *pDevice);
    virtual ~ArgoMTKViewDelegate() override;
    virtual void drawInMTKView(MTK::View *pView) override;

private:
    Renderer *_pRenderer;
};
