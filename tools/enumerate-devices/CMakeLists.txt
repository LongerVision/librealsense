# License: Apache 2.0. See LICENSE file in root directory.
# Copyright(c) 2019 Intel Corporation. All Rights Reserved.
#  minimum required cmake version: 3.1.0
cmake_minimum_required(VERSION 3.12.0)

project(RealsenseExamplesEnumerateDevices)

add_executable(rs-enumerate-devices rs-enumerate-devices.cpp)
set_property(TARGET rs-enumerate-devices PROPERTY CXX_STANDARD 11)
target_link_libraries( rs-enumerate-devices ${DEPENDENCIES}  )
set_target_properties (rs-enumerate-devices PROPERTIES
    FOLDER Tools
)

install(
    TARGETS

    rs-enumerate-devices

    RUNTIME DESTINATION
    ${CMAKE_INSTALL_BINDIR}
)
