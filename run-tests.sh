cmake -S . -B build\tests
cd build\tests
cmake --build .
ctest
