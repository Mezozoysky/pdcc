cmake_minimum_required(VERSION 3.13)

project(PDCC
    LANGUAGES CXX
    VERSION 0.1.0
)

set(PDCC_VERSION ${PROJECT_VERSION})

list(PREPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake/modules")

set(PDCC_BUILD_SHARED_DEFAULT ${BUILD_SHARED_LIBS})
set(PDCC_BUILD_UT_DEFAULT TRUE)

option(PDCC_BUILD_SHARED "Build shared libraries" ${PDCC_BUILD_SHARED_DEFAULT})
option(PDCC_BUILD_UT "Build unit tests" ${PDCC_BUILD_UT_DEFAULT})
option(PDCC_FMT_BUNDLED "Use bundled fmt library" TRUE)
#option(PDCC_SPDLOG_BUNDLED "Use bundled spdlog library" TRUE)

add_library(common INTERFACE)
add_library(PDCC::common ALIAS common)
target_compile_options(common
    INTERFACE
    $<$<CXX_COMPILER_ID:MSVC>:/Wall>
    $<$<CXX_COMPILER_ID:GNU,Clang>:-Wall -Wextra>
    )

add_subdirectory(dependencies)
add_subdirectory(sources)
