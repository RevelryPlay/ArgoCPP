#include "ArgoConfig.h"

// Mac OS Specific Code
#if defined(__APPLE__) && defined(__MACH__)

//#include "MacCommonIncludes.hpp"
#include "System/AppDelegate.hpp"

int main(int argc, char *argv[]) {
    fprintf(stdout, "running on mac\r\n");

    time_t now = time(0);
    char *dt = ctime(&now);
    std::cout << dt << std::endl;

    if (__cplusplus == 202101L) std::cout << "C++23";
    else if (__cplusplus == 202002L) std::cout << "C++20";
    else if (__cplusplus == 201703L) std::cout << "C++17";
    else if (__cplusplus == 201402L) std::cout << "C++14";
    else if (__cplusplus == 201103L) std::cout << "C++11";
    else if (__cplusplus == 199711L) std::cout << "C++98";
    else std::cout << "pre-standard C++." << __cplusplus;
    std::cout << "\n";

    NS::AutoreleasePool *pAutoreleasePool = NS::AutoreleasePool::alloc()->init();

    ArgoAppDelegate del;

    NS::Application *pSharedApplication = NS::Application::sharedApplication();
    pSharedApplication->setDelegate(&del);
    pSharedApplication->run();

    pAutoreleasePool->release();

    return 0;
}


#endif
