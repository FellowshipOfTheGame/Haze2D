include_directories (
	"include/"
	${SFML_INCLUDE_DIR})

# file (GLOB_RECURSE PROJECT_HEADERS include/*.hpp)
file (GLOB_RECURSE PROJECT_SOURCES src/*.cpp)
# file (GLOB_RECURSE PROJECT_SHADERS shaders/*.???)

source_group ("Headers" FILES ${PROJECT_HEADERS})
source_group ("Shaders" FILES ${PROJECT_SHADERS})
source_group ("Sources" FILES ${PROJECT_SOURCES})

add_library (${CMAKE_PROJECT_NAME} SHARED ${PROJECT_SOURCES}
	${PROJECT_SHADERS} ${PROJECT_CONFIGS})

set_target_properties (${CMAKE_PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME})
