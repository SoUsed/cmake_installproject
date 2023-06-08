# cmake_installproject
## Installation
1. from project root, run "mkdir build && cd build"
2. cmake .. && cmake --build .
3. cpack

result: installed package will be at build/package/functionator.zip

## Usage
1. Function format validator: ./validator *function*:
./validator "sin(x)"
2. Derivative finder: ./derivator *function*:
./derivator "-3*2^x" or ./derivator "tg(x)"
3. Integral finder: ./integrator *function*:
./integrator "5cos(x)" or ./integrator "ln(x)"

## Configuration
The list of available functions is limited to x^a, a^x, sin(x), cos(x), ln(x), c
Support of the other functions for derivator/integrator can be added via config files
Format: function=*its derivative/integral*:
tg(x)=1/cos^2(x)
