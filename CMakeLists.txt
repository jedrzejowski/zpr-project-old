cmake_minimum_required(VERSION 3.10)
project(zprProject)
find_package(PkgConfig)

#set(CMAKE_CXX_COMPILER "g++")
add_definitions("-lboost_system -Wall -pthread")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lboost_system")
#set(CMAKE_VERBOSE_MAKEFILE ON)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 0)
set(VERSION_RELEASE 1)


set(CMAKE_CXX_STANDARD 14)
set(APP_TARGET CraftMineBin)


include_directories(${PROJECT_SOURCE_DIR})
add_executable(${APP_TARGET}
		src/main.cpp src/game/GameWindow.cpp src/game/GameWindow.h)

# glfw
find_package(glfw3 REQUIRED)
include_directories(${GLFW_INCLUDE_DIRS})
link_libraries(${GLFW_LIBRARY_DIRS})

# opengl
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

# glew
find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})

# glm
find_package(glm REQUIRED)
include_directories(${GLM_INCLUDE_DIRS})
link_libraries(${GLM_LIBRARY_DIRS})

# orge3D
find_package(OGRE REQUIRED)
include_directories(${OGRE_INCLUDE_DIRS})
link_directories(${OGRE_LIBRARY_DIRS})

target_link_libraries(
		${APP_TARGET}
		${GLFW_LIBRARIES}
		${OPENGL_LIBRARIES}
		${GLEW_LIBRARIES}
		${GLM_LIBRARIES}
		${OGRE_LIBRARIES}
		${EXTRA_LIBS}
)

file(COPY ${OGRE_CONFIG_DIR}/plugins.cfg ${OGRE_CONFIG_DIR}/resources.cfg DESTINATION ${CMAKE_BINARY_DIR})
