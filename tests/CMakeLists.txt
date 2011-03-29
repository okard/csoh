
#tests and examples

add_executable(csoh_test_basic 
                ../ext/freeimage/fImage.cpp
                csoh_test_basic.cpp
               )
target_link_libraries(csoh_test_basic csoh "glut" "freeimage")
