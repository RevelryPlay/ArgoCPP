#pragma once
#include "MacCommonIncludes.hpp"

class Renderer {
public:
    Renderer(MTL::Device *pDevice);
    ~Renderer();

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
