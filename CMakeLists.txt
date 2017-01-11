## Haze2D CMake script ##

cmake_minimum_required(VERSION 2.6)

project (Haze2D)

option (SFML_STATIC_LIBRARIES "Use SFML static libraries instead of the dynamic ones" OFF)

# Include extra cmake modules
set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
# Try to find SFML in user's machine
find_package (SFML 2 COMPONENTS system graphics window audio network)
# Use 3rdparty one if SFML was not found
if (NOT SFML_FOUND)
	add_subdirectory (Haze2D/3rdparty/SFML)
	set (SFML_INCLUDE_DIR "Haze2D/3rdparty/SFML/include")
	set (SFML_LIBRARIES sfml-system sfml-network sfml-window sfml-audio sfml-graphics)
endif ()

if (MSVC)
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
else ()
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -std=c++11")
endif ()

add_subdirectory (Haze2D)
