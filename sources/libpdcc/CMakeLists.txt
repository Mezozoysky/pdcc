cmake_minimum_required(VERSION 3.13)

project(libpdcc
    LANGUAGES CXX
    VERSION ${PDCC_VERSION}
    )

add_library(${PROJECT_NAME} STATIC)
add_library(PDCC::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    LINKER_LANGUAGE CXX
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
    OUTPUT_NAME machine
    )
target_link_libraries(${PROJECT_NAME}
    INTERFACE
    #    spdlog::spdlog
    PDCC::common
    fmt::fmt
    )
target_include_directories(${PROJECT_NAME}
    PUBLIC
    "${CMAKE_CURRENT_LIST_DIR}"
    #    $<TARGET_PROPERTY:spdlog::spdlog,INTERFACE_INCLUDE_DIRECTORIES>
    $<TARGET_PROPERTY:fmt::fmt,INTERFACE_INCLUDE_DIRECTORIES>
    )

set(HEADER_FILES
    pdcc.hpp
    )
set(SOURCE_FILES
    pdcc.cpp
    )

target_sources(${PROJECT_NAME}
    PRIVATE ${SOURCE_FILES}
    PUBLIC ${HEADER_FILES}
    )

if(PDCC_BUILD_UT)
    add_subdirectory(ut)
endif()
