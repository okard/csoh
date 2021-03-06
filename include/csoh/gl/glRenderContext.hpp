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
#pragma once
#ifndef __CSOH_GLRENDERER_HPP__
#define __CSOH_GLRENDERER_HPP__

#include <csoh/gl/OpenGL.hpp>

#include <csoh/gl/glState.hpp>

namespace csoh {

class RenderContext;

class glBufferObject;


/**
* OpenGL Renderer
*/
class glRenderContext
{
private:
    /// Is Render Initialized
    bool initialized;
    
    /// root context
    RenderContext& rootRenderContext_;
    
public:

    /**
    * Create new OpenGL renderer
    */
    glRenderContext(RenderContext& rootRenderContext);
    
    /**
    * Destroy OpenGL renderer
    */
    ~glRenderContext();
    
    /**
    * Initialize Renderer
    */
    void initialize();
    
    /**
    * Resize OpenGL Viewport
    */
    void resize(int x, int y, int width, int height);
    
    /**
    * Start Rendering Scene
    */
    void renderStart();
    
    /**
    * Finshing Render Scene
    */
    void finishRender();
    
    //render context exist?
    
    /**
    * Is initialized
    */
    bool isInitialized();
};

} //end namespace csoh

#endif // __CSOH_GL_RENDERER_HPP__
