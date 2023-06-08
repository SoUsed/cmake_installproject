project(derivator)

include_directories(../common/)
include_directories(../configparser)
add_executable(derivator derivator.cpp)
#file(COPY derivatives.conf DESTINATION ${PROJECT_BINARY_DIR}/derivator/)