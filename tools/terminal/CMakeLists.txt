# License: Apache 2.0. See LICENSE file in root directory.
# Copyright(c) 2019 Intel Corporation. All Rights Reserved.
#  minimum required cmake version: 3.1.0
cmake_minimum_required(VERSION 3.12.0)

project(RealsenseToolsTerminal)
include_directories(
        ../../common
        ../../third-party
        )
set(RS_TERMINAL_SOURCES
        rs-terminal.cpp
        auto-complete.cpp
        auto-complete.h
        ../../common/parser.hpp
    )
add_executable(rs-terminal ${RS_TERMINAL_SOURCES})
set_property(TARGET rs-terminal PROPERTY CXX_STANDARD 11)
if(WIN32 OR ANDROID)
    target_link_libraries(rs-terminal ${DEPENDENCIES} )
else()
    target_link_libraries(rs-terminal -lpthread ${DEPENDENCIES} )
endif()
set_target_properties (rs-terminal PROPERTIES
    FOLDER Tools
)

install(
    TARGETS

    rs-terminal

    RUNTIME DESTINATION
    ${CMAKE_INSTALL_BINDIR}
)

