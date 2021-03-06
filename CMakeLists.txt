#Change this if you need to target a specific CMake version
cmake_minimum_required(VERSION 2.6)
project(tribble)

SET(CMAKE_BUILD_TYPE Debug)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Ofast -std=c++11 -Wunknown-pragmas -Wdelete-non-virtual-dtor")

# Enable debug symbols by default
if(CMAKE_BUILD_TYPE STREQUAL "")
set(CMAKE_BUILD_TYPE Debug)
endif()
# (you can also set it on the command line: -D CMAKE_BUILD_TYPE=Release)

# Set version information in a config.h file
set(tribble_VERSION_MAJOR 1)
set(tribble_VERSION_MINOR 0)
set(PROJECT_SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
configure_file(
"${PROJECT_SOURCE_DIR}/config.h.in"
"${PROJECT_BINARY_DIR}/config.h"
)
include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_SOURCE_DIR}/Client")
include_directories("${PROJECT_SOURCE_DIR}/Engine")
include_directories("${PROJECT_SOURCE_DIR}/Framework")

# Define sources and executable
set(EXECUTABLE_NAME "tribble")

add_executable(${EXECUTABLE_NAME} ${PROJECT_SOURCE_DIR}/Main.cpp)


#set up linux search paths
set(LIBRARY_SEARCH_PATH
/usr/local
/opt/local
/usr
/opt
)


set(HEADER_SEARCH_PATH
/usr/local
/opt/local
/usr
/opt
)


# Find OpenGL
find_package(OpenGL)
find_package(X11)


# Find glfw header
find_path(GLFW_INCLUDE_DIR GLFW/glfw3.h ${HEADER_SEARCH_PATH})


# Find glfw library
find_library(GLFW_LIBRARIES glfw3 ${LIBRARY_SEARCH_PATH})

add_subdirectory(${PROJECT_SOURCE_DIR}/Framework)
add_subdirectory(${PROJECT_SOURCE_DIR}/Engine)

#file(GLOB SRCS_Framework ${PROJECT_SOURCE_DIR}/Framework/*.cpp)
#file(GLOB HDRS_Framework ${PROJECT_SOURCE_DIR}/Framework/*.h)

#add_library(${Framework} ${SRCS_Framework} ${HDRS_Framework})

#file(GLOB SRCS_Engine ${PROJECT_SOURCE_DIR}/Engine/*.cpp)
#add_library(test ${SRCS_Framework}  ${SRCS_Engine})

target_link_libraries(${EXECUTABLE_NAME} project_Engine project_Framework)


# Set additional libs
set( ADDITIONAL_LIBS 
-lglfw3
-lGLEW
-lGLU
-lGL
-pthread
-lrt
-lXinerama
-lXrandr
-lXxf86vm
-lXi
-lXcursor
)

#-lGLU 

# Include directories for this project
set(INCLUDE_PATH
${OPENGL_INCLUDE_DIR}
${GLFW_INCLUDE_DIR}
)


# Libraries needed on all platforms for this project
set(LIBRARIES
${OPENGL_LIBRARIES}
${GLFW_LIBRARIES}
${X11_LIBRARIES}
${ADDITIONAL_LIBS}  
)


# Windows and Linux need GLEW, the OpenGL Extension Wrangler
find_path(GLEW_INCLUDE_DIR GL/glew.h
${HEADER_SEARCH_PATH}
)


set(INCLUDE_PATH ${INCUDE_PATH}
${GLEW_INCLUDE_DIR} 
)


# Add a target executable
#add_executable(${EXECUTABLE_NAME}
#PROJECT ${CMAKE_SOURCE_DIR}/Main.cpp
#)


# Libraries to be linked
target_link_libraries(${EXECUTABLE_NAME}
${LIBRARIES}
)

# Detect and add EntityX
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(EntityX REQUIRED)
if(ENTITYX_FOUND)
include_directories(${ENTITYX_INCLUDE_DIR})
target_link_libraries(${EXECUTABLE_NAME} ${ENTITYX_LIBRARY})
endif()

# Detect and add LibDL
#set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(LibDL REQUIRED)
if(LIBDL_FOUND)
include_directories(${LIBDL_INCLUDE_DIR})
target_link_libraries(${EXECUTABLE_NAME} ${LIBDL_LIBRARIES})
endif()

# Detect and add OpenGL
#find_package(OpenGL REQUIRED)
#if(OPENGL_FOUND)
#include_directories(${OPENGL_INCLUDE_DIR})
#target_link_libraries(${EXECUTABLE_NAME} #${OPENGL_LIBRARY})
#endif()

# Install target
#install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)

# CPack packaging
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE")
set(CPACK_PACKAGE_VERSION_MAJOR "${terrific_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${terrific_VERSION_MINOR}")
include(CPack)