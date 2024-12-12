add_library(
    logger
    INTERFACE
    Logger/Logger.hpp
)

target_include_directories(
    logger
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

install(
    TARGETS logger
    EXPORT ${CMAKE_PROJECT_NAME}
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/Logger/cmake
)

install(
    FILES Logger/Logger.hpp
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/Logger
)

