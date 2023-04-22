#pragma once
#include "MacCommonIncludes.hpp"
#include "Graphics/ViewDelegate.hpp"

class ArgoAppDelegate : public NS::ApplicationDelegate {
public:
    ~ArgoAppDelegate();

    NS::Menu *createMenuBar();

    virtual void applicationWillFinishLaunching(NS::Notification *pNotification) override;
    virtual void applicationDidFinishLaunching(NS::Notification *pNotification) override;
    virtual bool applicationShouldTerminateAfterLastWindowClosed(NS::Application *pSender) override;

private:
    NS::Window *_pWindow;
    MTK::View *_pMtkView;
    MTL::Device *_pDevice;
    ArgoMTKViewDelegate *_pViewDelegate = nullptr;
};
