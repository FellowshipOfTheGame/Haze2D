include_directories(include)

file (GLOB_RECURSE DEMO_SOURCES src/*.cpp)

add_executable(demo ${DEMO_SOURCES})

target_link_libraries (demo ${CMAKE_PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES} ${BOX2D_LIBRARIES})