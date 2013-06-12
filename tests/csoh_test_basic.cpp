/*
    C++ 3D Graphic Engine

    Copyright (c) 2011  okard

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
*/

//CSOH specific
#include <csoh/RenderContext.hpp>
#include <csoh/Shader.hpp>
#include <csoh/Image.hpp>
#include <csoh/Mesh.hpp>
#include <ext/freeimage/fImage.hpp>

//CSOH OpenGL Specific
#include <csoh/gl/glShaderResources.hpp>

// Create Window
#include <GL/freeglut.h>

using csoh::RenderContext;
using csoh::Mesh;
using csoh::fImage;

// keyboard events
void keyboard(unsigned char key, int x, int y);
//display function
void display();
//reshpare function
void reshape(int width, int height);

/**
* Basic Test
*/
class BasicTest
{
private:
    ///render context
    RenderContext ctx;
    
    
public:
    
    //initialize
    void init()
    {
        ctx.init();
        
        //create opengl mesh
    }
    
    //render
    void render()
    {
        //start rendering a frame
        ctx.startRender();
        
        //render mesh here
        
        ctx.finishRender();
    }
    
    void reshape(int width, int height)
    {
        ctx.resize(0, 0, width, height);
    }
    
    
};

//Basic Test 
BasicTest test;
    
/**
* Main Function
*/
int main(int argc, char *argv[])
{
    //Initialize GLUT
    glutInit(&argc, argv);
    glutCreateWindow("CSOH Test");
    
    test.init();
    //Set Callback Function and start main loop
    glutReshapeFunc(&reshape);
    glutKeyboardFunc(&keyboard);
    glutDisplayFunc(&display);
    
	glutReshapeWindow(1024, 768);
    glutMainLoop();
    
    return 0;
}

/**
* Keyboard Handler
*/
void keyboard(unsigned char key, int x, int y)
{
    glutLeaveMainLoop();
}

/**
* Display Function
*/
void display()
{
    test.render();
    //swap buffer
    glutSwapBuffers();
}

/**
* Reshape Function
*/
void reshape(int width, int height)
{
    test.reshape(width, height);
}
