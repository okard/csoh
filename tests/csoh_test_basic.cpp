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

static struct
{
    //the renderer
    RenderContext rend;
    //Image
    fImage texture;
    //mesh to display
    Mesh* mesh;
    
} base;

/**
* Main Function
*/
int main(int argc, char *argv[])
{
    //Initialize GLUT
    glutInit(&argc, argv);
    glutCreateWindow("CSOH Test");
    glutReshapeWindow(1024, 768);
    
    //initializes csoh rendering engine (requires valid openGL Context)
    base.rend.init();
    
    //load texture
    base.texture.read("data/texture1.png");
    
    //glTexture tex;
    //tex.load(&base.texture);
    
    base.mesh = new Mesh();
    
    //load vertexes
    //load index
    //(load material)
    //load textures
    //load shaders
    
    //test to render something
    
    
    
    
    //load shader
    //csoh::ShaderProgram shader;
    //shader.load(csoh::BaseVertexShader, csoh::SimpleFragmentShader1T);
    //shader.use();
    
    //set texture to shader
    
    //base.mesh = new glMesh();

    
    //create scene graph here
    //add camera
    
    //Set Callback Function and start main loop
    glutReshapeFunc(&reshape);
    glutKeyboardFunc(&keyboard);
    glutDisplayFunc(&display);
    glutMainLoop();
    
    
    //clean up memory here
    delete base.mesh;
    
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
    //start rendering a frame
    base.rend.startRender();
    base.rend.finishRender();
    
    //swap buffer
    glutSwapBuffers();
}

/**
* Reshape Function
*/
void reshape(int width, int height)
{
    //resize the rendering interface
    base.rend.resize(0, 0, width, height);
}