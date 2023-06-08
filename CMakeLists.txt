project(functionator)

add_subdirectory(common)
add_subdirectory(configparser)
add_subdirectory(derivator)
add_subdirectory(integrator)
add_subdirectory(test)

set(INSTALL_DIR "${CMAKE_CURRENT_BINARY_DIR}/install")

install(TARGETS validator derivator integrator
    RUNTIME DESTINATION ${INSTALL_DIR}
)

install(FILES
    derivator/derivatives.conf
    integrator/integrals.conf
    DESTINATION ${INSTALL_DIR}/config
)

set(CPACK_GENERATOR "ZIP")
set(CPACK_PACKAGE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/package")
set(CPACK_PACKAGE_FILE_NAME "${PROJECT_NAME}")
set(CPACK_INCLUDE_TOPLEVEL_DIRECTORY OFF)
include(CPack)