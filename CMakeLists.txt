#########################################
# CMake File for csoh
######################################### 
cmake_minimum_required(VERSION 2.8)
project(csoh)


include_directories(include)
include_directories(.)
find_package(OpenGL)

set(CSOH_SRC
    src/Image.cpp
    src/Math.cpp
    src/Renderer.cpp
    src/Shader.cpp
    src/Timer.cpp
    src/gl/glTexture.cpp
    src/gl/glShader.cpp
    src/gl/glRenderer.cpp
    src/gl/glVertexBuffer.cpp
    )

add_library(csoh ${CSOH_SRC})
target_link_libraries(csoh "rt" "GLEW" ${OPENGL_LIBRARIES})

# test directory
add_subdirectory(tests)

