cmake_minimum_required(VERSION 3.1)
project(OpenGL)

if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU" OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++11 -pthread")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG} -g")
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE} -O2")
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
	if (CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
		string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
	else()
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
	endif()
endif()

set(CMAKE_MODULE_PATH /usr/local/lib/cmake /usr/local/lib/x86_64-linux-gnu/cmake)
set(CMAKE_PREFIX_PATH /usr/local/lib/cmake/glfw)

set(SOURCE_FILES main.cpp)
add_executable(OpenGL ${SOURCE_FILES} Cwindow.h Cwindow.cpp)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package (GLM REQUIRED)
find_package(PkgConfig REQUIRED)
find_package (GLEW REQUIRED STATIC)
pkg_search_module(GLFW REQUIRED glfw3)

include_directories(${GLFW_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS})

target_link_libraries( OpenGL ${OPENGL_LIBRARIES} ${GLFW_LIBRARIES} ${GLFW_STATIC_LIBRARIES} ${GLEW_LIBRARY}
Xxf86vm pthread Xrandr Xinerama Xi Xcursor)