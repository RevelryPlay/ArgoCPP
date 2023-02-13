#pragma once

#include "ArgoConfig.h"
#include "WindowImGUI.hpp"

namespace Argo {
    static void glfw_error_callback(int error, const char *description) {
        fprintf(stderr, "Glfw Error %d: %s\n", error, description);
    }

    WindowImGUI::WindowImGUI() {
        WindowImGUI(800, 600, "Default Window");
    }

    WindowImGUI::WindowImGUI(int width, int height, const char *title) {
        /* Initialize the library */
        if (!glfwInit())
            return;

        glfwSetTime(0);

        glfwSetErrorCallback(glfw_error_callback);

        const char *glsl_version = "#version 150";
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

        // Create window with graphics context
        this->window = glfwCreateWindow(width, height, title, NULL, NULL);
        if (!this->window) {
            glfwTerminate();
            return;
        }

        glfwMakeContextCurrent(this->window);

        /* Load glad */
        int version = gladLoadGL(glfwGetProcAddress);
        if (version == 0) {
            fprintf(stderr, "Failed to initialize OpenGL context\n");
            return;
        }

        glViewport(0, 0, width, height);

        glfwSwapInterval(1); // Enable vsync

        // Setup Dear ImGui context
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO &io = ImGui::GetIO();
        (void) io;

        // Setup Dear ImGui style
        ImGui::StyleColorsDark();

        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
        io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows

        ImGuiStyle &style = ImGui::GetStyle();
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
            style.WindowRounding = 0.0f;
            style.Colors[ImGuiCol_WindowBg].w = 1.0f;
        }

        ImGui_ImplGlfw_InitForOpenGL(this->window, true);
        ImGui_ImplOpenGL3_Init(glsl_version);

        io.Fonts->AddFontFromFileTTF(R"(c:\Windows\Fonts\segoeui.ttf)", 18.0f);

//        this->clearColorVec4 = Argo::Utilities::ConvertColor(0x1f7fbfff).ToVec4();

    }

    void WindowImGUI::Update() {
        if (!this->window) {
            return;
        }

        if (glfwWindowShouldClose(this->window)) {
            this->Close();
            return;
        }

        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        this->CreateDockSpace();
        this->RenderFrame();

        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);

//        Utilities::Vec4 clearColorVec4 = Argo::Utilities::ConvertColor(0x1f7fbfff).ToVec4();

        Utilities::Vec4 clearColorVec4 = {0.121568628, 0.498039216, 0.749019622, 1};

        glClearColor(clearColorVec4.x * clearColorVec4.w,
                     clearColorVec4.y * clearColorVec4.w,
                     clearColorVec4.z * clearColorVec4.w,
                     clearColorVec4.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        GLFWwindow *backup_current_context = glfwGetCurrentContext();
        ImGui::UpdatePlatformWindows();
        ImGui::RenderPlatformWindowsDefault();
        glfwMakeContextCurrent(backup_current_context);

        glfwSwapBuffers(window);
    }

    void WindowImGUI::CreateDockSpace() {
        static bool opt_fullscreen = true;
        static bool opt_padding = false;
        static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

        // We are using the ImGuiWindowFlags_NoDocking flag to make the parent window not dockable into,
        // because it would be confusing to have two docking targets within each others.
        ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
        if (opt_fullscreen) {
            const ImGuiViewport *viewport = ImGui::GetMainViewport();
            ImGui::SetNextWindowPos(viewport->WorkPos);
            ImGui::SetNextWindowSize(viewport->WorkSize);
            ImGui::SetNextWindowViewport(viewport->ID);
            ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
            ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
            window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize |
                            ImGuiWindowFlags_NoMove;
            window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
        } else {
            dockspace_flags &= ~ImGuiDockNodeFlags_PassthruCentralNode;
        }

        // When using ImGuiDockNodeFlags_PassthruCentralNode, DockSpace() will render our background
        // and handle the pass-thru hole, so we ask Begin() to not render a background.
        if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
            window_flags |= ImGuiWindowFlags_NoBackground;

        // Important: note that we proceed even if Begin() returns false (aka window is collapsed).
        // This is because we want to keep our DockSpace() active. If a DockSpace() is inactive,
        // all active windows docked into it will lose their parent and become undocked.
        // We cannot preserve the docking relationship between an active window and an inactive docking, otherwise
        // any change of dockspace/settings would lead to windows being stuck in limbo and never being visible.
        if (!opt_padding)
            ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
        ImGui::Begin("DockSpace Demo", reinterpret_cast<bool *>(true), window_flags);
        if (!opt_padding)
            ImGui::PopStyleVar();

        if (opt_fullscreen)
            ImGui::PopStyleVar(2);

        // Submit the DockSpace
        ImGuiIO &io = ImGui::GetIO();
        if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable) {
            ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
            ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
        }


        ImGui::End();
    }

    void WindowImGUI::RenderFrame() {
        ImGui::Begin("Hello, world!");

        ImGui::ShowStyleEditor();

        ImGui::Dummy(ImVec2(0.0f, 30.0f));

        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate,
                    ImGui::GetIO().Framerate);

        ImGui::Dummy(ImVec2(0.0f, 30.0f));

        ImGui::Text("Application Version %d.%d.%d", ARGO_VERSION_MAJOR, ARGO_VERSION_MINOR, ARGO_VERSION_PATCH);
        ImGui::End();
    }

    WindowImGUI::~WindowImGUI() {
        Close();
    }

    void WindowImGUI::Close() {
        if (!this->window) {
            return;
        }

        // Cleanup
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();

        glfwDestroyWindow(this->window);
        glfwTerminate();

        this->window = nullptr;
    }

    bool WindowImGUI::IsOpen() {
        return this->window != nullptr;
    }
}
