#ifndef ARGOCPP_COMMON_HPP
#define ARGOCPP_COMMON_HPP

// Windows Specific Code
#ifdef _WIN32
    #include "WindowsCommonIncludes.hpp"
#endif

// Mac OS Specific Code
#if defined(__APPLE__) && defined(__MACH__)
    #include "MacCommonIncludes.hpp"
#endif

#endif
