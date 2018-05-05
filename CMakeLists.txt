cmake_minimum_required(VERSION 3.10)
project(zprProject)
find_package(PkgConfig)

#set(CMAKE_CXX_COMPILER "clang")
#/add_definitions("-lboost_system -Wall -pthread")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lboost_system")
#set(CMAKE_VERBOSE_MAKEFILE ON)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 0)
set(VERSION_RELEASE 1)


set(CMAKE_CXX_STANDARD 14)
set(APP_TARGET CraftMineBin)


include_directories(${PROJECT_SOURCE_DIR})

add_executable(${APP_TARGET}
		src/main.cpp

		src/game/GameManager.cpp
		src/game/GameManager.h

		src/game/Camera.cpp
		src/game/Camera.h

		src/sys/Path.cpp
		src/sys/Path.h
		src/sys/ResourceLoader.cpp
		src/sys/ResourceLoader.h
		src/world/Chunk.cpp src/world/Chunk.h src/world/World.cpp src/world/World.h)

#Blocks
target_sources(${APP_TARGET} PUBLIC
		src/block/Abstract.cpp
		src/block/Abstract.h

		src/block/SolidAbstract.cpp
		src/block/SolidAbstract.h

		src/block/terrain/Stone.cpp
		src/block/terrain/Stone.h)


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

configure_file(resources.cfg resources.cfg COPYONLY)