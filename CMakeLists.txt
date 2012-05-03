#########################################
# CMake File for csoh
######################################### 
cmake_minimum_required(VERSION 2.8)
project(csoh)


include_directories(include)
include_directories(.)
find_package(OpenGL)

# C++11
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -std=c++11")

# Set up source files
file(GLOB_RECURSE CSOH_SRC src/*.c*)

#export lib functions under windows
add_definitions(-DCSOH_LIBRARY)

add_library(csoh STATIC ${CSOH_SRC})
target_link_libraries(csoh "rt" "dl" ${OPENGL_LIBRARIES})

# copy to lib folder
get_target_property(CSOH_LIB_NAME csoh LOCATION)
add_custom_command(TARGET csoh POST_BUILD
    COMMAND cp ARGS ${CSOH_LIB_NAME} ${CMAKE_CURRENT_LIST_DIR}/lib/
)

# test directory
add_subdirectory(tests)

