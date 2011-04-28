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
#include <csoh/gl/glRenderer.hpp>
#include <csoh/gl/glBufferObject.hpp>
#include <csoh/Exception.hpp>

using csoh::glRenderer;
using csoh::Exception;

/**
* Create new OpenGL renderer
*/
glRenderer::glRenderer()
{
    //initialize stuff which doesnt require opengl context
}

/**
* Destroy OpenGL renderer
*/
glRenderer::~glRenderer()
{
    
}

/**
* Initialize Renderer
*/
void glRenderer::initialize()
{
    static bool static_init = false;
    
    //Get only one initialized in whole program
    if(!static_init)
    {
        static_init = true;
        
        //Initialize GLEW Library
        GLenum err = glewInit();
        if (GLEW_OK != err)
        {
            throw Exception(reinterpret_cast<const char*>(glewGetErrorString(err)));
        }
        
        
        if (!GLEW_VERSION_2_1)
        {
            //check support for OpenGL here
            throw Exception("OpenGL >2.1 required");
        }
    }
    //Check for OpenGL Context
    //at this moment a OpenGL Context must exist
    //when embedding glew init glew here?
    //only when not already initialized
    
    //set clear color
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
}


/**
* Resize OpenGL Viewport
*/
void glRenderer::resize(int x, int y, int width, int height)
{
    if (height==0)
        height=1;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    //near/far clipping?
    gluPerspective(45.0, width/height, 1, 1000);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

/**
* Start Render
*/
void glRenderer::renderStart()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
}



/**
* Render a vertex buffer with element buffer
*/
void glRenderer::render(glBufferObject* const vbo, glBufferObject* const ebo)
{
    vbo->bind();
    //required right format per glVertexAttribPointer from vbo
    
    ebo->bind();
    //data from ebo?
    glDrawElements(GL_TRIANGLE_STRIP,  4, GL_UNSIGNED_SHORT,  (void*)0);
}



