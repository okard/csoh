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
#include <csoh/RenderContext.hpp>

using csoh::RenderContext;

/**
* Create new renderer
*/
RenderContext::RenderContext()
	: render_(*this)
	, viewMatrix_(1.0f)
	, projectionMatrix_(1.0f)
{
    //Initialize all Stuff that doesnt require a active graphic context
    
    timer_.start();
    
    
    //TODO explain
    viewMatrix_ = math::lookAt(Vec3f(0.0, 2.0, 0.0), Vec3f(0.0, 0.0, -4.0), Vec3f(0.0, 1.0, 0.0));
}

/**
* Destructs renderer
*/
RenderContext::~RenderContext()
{
    timer_.stop();
}

/**
* Initialize Renderer
* May require valid Graphic Context
*/
void RenderContext::init()
{
    render_.initialize();
}

/**
* Resize Render Viewport
*/
void RenderContext::resize(int width, int height)
{
	widthpx_ = width;
	heightpx_ = heightpx_;
    render_.resize(0, 0, width, height);
    
    //TODO explain
    projectionMatrix_ = math::perspective(45.0f, 1.0f*width/height, 0.1f, 10.0f);
}

/**
* Start Render Scene
*/
void RenderContext::startRender()
{
    //get time here?
    //calcualte frames?
    float t = timer_.time(true);
    
    render_.renderStart();
}


/**
* Finshing Render Scene
*/
void RenderContext::finishRender()
{
    //post rendering effects?
    render_.finishRender();
}


/**
* Exists a valid render context?
*/
bool RenderContext::existValidRenderContext()
{
    return false;
}
