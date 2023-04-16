// Mac OS Specific Code
#if defined(__APPLE__) && defined(__MACH__)

#include "MacCommonIncludes.hpp"

int main(int, char **) {
    fprintf(stdout, "running on mac");
    return 0;
}

#endif
