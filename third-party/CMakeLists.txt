string(REPLACE ${PROJECT_SOURCE_DIR}/ "" _rel_path ${CMAKE_CURRENT_LIST_DIR})

# Include external JSON configuration
include(CMake/external_json.cmake)

# Find the installed packages using pkg-config
find_package(PkgConfig REQUIRED)
pkg_check_modules(TCLAP REQUIRED tclap)
pkg_check_modules(EASYLOGGINGPP REQUIRED easyloggingpp)

# Include directories for the found packages
include_directories(${TCLAP_INCLUDE_DIRS})
include_directories(${EASYLOGGINGPP_INCLUDE_DIRS})

# Manually specify include directories and link the rsutils library
include_directories(/usr/local/include/rsutils)  # Adjust this path if your headers are located elsewhere
link_libraries(/usr/local/lib/librsutils.so)

# Manually specify include directories and link the realsense-file library
include_directories(/usr/local/include/realsense-file)  # Adjust this path if your headers are located elsewhere
link_libraries(/usr/local/lib/librealsense-file.so)

# Link the appropriate libraries
link_libraries(${TCLAP_LIBRARIES})
link_libraries(${EASYLOGGINGPP_LIBRARIES})

# Add additional include directories to allow file to include rosbag headers
include(${_rel_path}/realsense-file/config.cmake)

if(BUILD_EASYLOGGINGPP)
    include_directories(${EASYLOGGINGPP_INCLUDE_DIRS})
    link_libraries(${EASYLOGGINGPP_LIBRARIES})
endif()

# Note: The external JSON library handling will be updated later
# Add_subdirectory for realdds
if(BUILD_WITH_DDS)
    add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/realdds")
endif()
