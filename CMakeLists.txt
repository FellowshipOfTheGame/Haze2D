cmake_minimum_required(VERSION 3.0)
project(Haze2D)

add_subdirectory(Haze2D/3rdparty/SFML)

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -std=c++11")
    if(NOT WIN32)
        set(GLAD_LIBRARIES dl)
    endif()
endif()

include_directories(Haze2D/include/
        Haze2D/include/Core/
        Haze2D/include/Audio/
        Haze2D/include/Graphics/
        Haze2D/include/Physics/
        Haze2D/3rdparty/SFML/include)

file(GLOB PROJECT_HEADERS Haze2D/include/*.hpp
        Haze2D/include/Core/*.hpp
        Haze2D/include/Audio/*.hpp
        Haze2D/include/Graphics/*.hpp
        Haze2D/include/Physics/*.hpp)

file(GLOB PROJECT_SOURCES Haze2D/src/*.cpp
        Haze2D/src/Core/*.cpp
        Haze2D/src/Audio/*.cpp
        Haze2D/src/Graphics/*.cpp
        Haze2D/src/Physics/*.cpp)

source_group("Headers" FILES ${PROJECT_HEADERS})
source_group("Shaders" FILES ${PROJECT_SHADERS})
source_group("Sources" FILES ${PROJECT_SOURCES})

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${PROJECT_HEADERS}
                               ${PROJECT_SHADERS} ${PROJECT_CONFIGS})

target_link_libraries(${PROJECT_NAME} sfml-system sfml-network sfml-window sfml-audio sfml-graphics)

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME})
