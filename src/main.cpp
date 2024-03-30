#include <exception>
#include <iostream>

#include "../Core/include/ArgoProject.hpp"
#include "../Graphics/include/Renderer.hpp"

#include "ArgoConfig.h"
#include "Demo.hpp"

#include <ArgoDraft/ArgoDraft.hpp>
#include <ArgoDraft/ConsoleMenu.hpp>

void NotImplemented() { std::cout << "Not implemented yet" << '\n'; }

void CreateNew() {
    std::cout << "Creating a new project" << '\n';
    const auto* const project = new Argo::Core::Project("Test", "Test Project", "", false, "0.0.1", "0.0.1");

    // Should open the editor to the new project

    std::cout << "Project Name: " << project->name << '\n';
    std::cout << "Project Description: " << project->desc << '\n';
    std::cout << "Project Version: " << project->ver << '\n';
    std::cout << "Argo Min Version: " << project->argoMin << '\n';
    std::cout << "Argo Target Version: " << project->argoTarget << '\n';
}

int main(int /*argc*/, char** /*argv*/) {
    try {
        std::cout << "Welcome to " << PROJECT_NAME << '\n';
        std::cout << PROJECT_DESCRIPTION << '\n';
        std::cout << "Version " << PROJECT_VERSION_MAJOR << "." << PROJECT_VERSION_MINOR << "." << PROJECT_VERSION_PATCH
                << "." << PROJECT_VERSION_TWEAK << '\n';
        std::cout << '\n';
        std::cout << "Project Homepage " << PROJECT_URL << '\n';
        std::cout << "For help getting started please see the " << PROJECT_NAME
                << " documentation at https://docs.revelryplay.com/argo" << '\n';
        std::cout << '\n';
        std::cout << "To see a list of available commands type `help`" << '\n';
        std::cout << '\n';

        auto* menu = new ArgoDraft::MainMenu();
        menu->AddAction({"ArgoDraft", "Information about this library", ArgoDraft::about});

        menu->AddAction({"new", "Create a new project and open the argo Editor", CreateNew});

        auto* subMenu = new ArgoDraft::Menu("demo", "Open the Demo project");
        subMenu->AddAction({"edit", "Open the Argo editor", []() { Argo::Graphics::Renderer::render(); }});
        subMenu->AddAction({
            "run", "Run the project", []() {
                const auto* demo = new Argo::Demo();
                demo->Run();
            }
        });

        menu->AddMenu(*subMenu);

        menu->Init();
    }
    catch (const std::exception&e) {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }

    return 0;
}
