#pragma once
#include "Common.hpp"

#include "ArgoRenderer.hpp"

class ArgoMTKViewDelegate : public MTK::ViewDelegate {
public:
    ArgoMTKViewDelegate(MTL::Device *pDevice);
    virtual ~ArgoMTKViewDelegate() override;
    virtual void drawInMTKView(MTK::View *pView) override;

private:
    ArgoRenderer *_pRenderer;
};
