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
    src/RenderContext.cpp
    src/Shader.cpp
    src/Timer.cpp
    src/Utils.cpp
    src/gl/glTexture.cpp
    src/gl/glShader.cpp
    src/gl/glRenderer.cpp
    src/gl/glBufferObject.cpp
    src/gl/glMesh.cpp
    )

#export lib functions under windows
add_definitions(-DCSOH_LIBRARY)

add_library(csoh STATIC ${CSOH_SRC})
target_link_libraries(csoh "rt" "GLEW" ${OPENGL_LIBRARIES})

# test directory
add_subdirectory(tests)

