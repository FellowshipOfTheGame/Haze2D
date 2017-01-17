## Haze2D CMake script ##

cmake_minimum_required(VERSION 2.6)

project (Haze2D)

option (SFML_STATIC_LIBRARIES "Use SFML static libraries instead of the dynamic ones" OFF)
option (BOX2D_BUILD_SHARED "Build Box2D shared libraries" OFF)
option (BOX2D_BUILD_STATIC "Build Box2D static libraries" ON)
option (BOX2D_BUILD_EXAMPLES "Build Box2D examples" OFF)
option (BOX2D_INSTALL "Install Box2D libs, includes, and CMake scripts" ON)

set (SFML_STATIC_LIBRARIES OFF)
set (BOX2D_BUILD_SHARED OFF)
set (BOX2D_BUILD_STATIC ON)
set (BOX2D_BUILD_EXAMPLES OFF)
set (BOX2D_INSTALL ON)

# Include extra cmake modules
set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
# Try to find SFML and Box2D in user's machine
find_package (SFML 2 COMPONENTS system graphics window audio network)
find_package (Box2D)

if (MSVC)
	set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
else ()
	set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -std=c++11")
endif ()

# Use 3rdparty one if SFML was not found
if (NOT SFML_FOUND)
	add_subdirectory (Haze2D/3rdparty/SFML)
	set (SFML_INCLUDE_DIR "Haze2D/3rdparty/SFML/include")
	set (SFML_LIBRARIES sfml-system sfml-network sfml-window sfml-audio sfml-graphics)
endif ()

# Use 3rdparty one if Box2D was not found
if (NOT BOX2D_FOUND)
	add_subdirectory (Haze2D/3rdparty/Box2D/Box2D)
	set (BOX2D_INCLUDE_DIR "Haze2D/3rdparty/Box2D/Box2D")
	set (BOX2D_LIBRARIES Box2D)
endif()

include_directories (
		"Haze2D/include/"
		${SFML_INCLUDE_DIR}
		${BOX2D_INCLUDE_DIR}
)

add_subdirectory (Haze2D)
add_subdirectory (demo)
