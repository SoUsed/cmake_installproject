project(derivator)

include_directories(../common/)
include_directories(../configparser)
add_executable(integrator integrator.cpp)
message(${PROJECT_BINARY_DIR}/integrator/)
#file(COPY integrals.conf DESTINATION ${PROJECT_BINARY_DIR}/integrator/)