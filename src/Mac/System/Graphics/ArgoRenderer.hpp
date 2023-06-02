#pragma once
#include "Common.hpp"

class ArgoRenderer {
public:
    ArgoRenderer(MTL::Device *pDevice);
    ~ArgoRenderer();

    void buildShaders();
    void buildBuffers();
    void draw(MTK::View *pView);

private:
    MTL::Device *_pDevice;
    MTL::CommandQueue *_pCommandQueue;
    MTL::RenderPipelineState *_pPSO;
    MTL::Buffer *_pVertexPositionsBuffer;
    MTL::Buffer *_pVertexColorsBuffer;
};
