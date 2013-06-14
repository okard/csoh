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
#ifndef __CSOH_GLVERTEXBUFFER_HPP__
#define __CSOH_GLVERTEXBUFFER_HPP__

#include <csoh/gl/OpenGL.hpp>

namespace csoh {
    
//forward declaration
class glRenderContext;

/**
* OOP Wrapper for Buffer Objects
*/
class glBufferObject
{
private:
    /// Buffer id
    GLuint vboId;
    
    /// Buffer Type
    GLenum type; 
public:
    
    /**
    * Create new Vertex Buffer Object
    */
    glBufferObject(glRenderContext* ctx, GLenum type);

    /**
    * Create new Vertex Buffer Object
    */
    glBufferObject(GLenum type);
    
    /**
    * Destructs Vertex Buffer Object
    */
    ~glBufferObject();
    
    /**
    * Bind Vertex Buffer (adding context to manage?)
    */
    void bind();
    
    //static void unbind(GLenum type);
    
    /**
    * Set Buffer Data
    */
    void setBufferData(const void *bufferData, GLsizei bufferSize, GLenum usage);
    
    /**
    * Update Buffer Data
    */
    void updateBufferData(GLintptr  offset, const void *bufferData, GLsizei bufferSize);
    
    /**
    * Map Buffer
    */
    void* map(GLenum access);

    /**
    * Unmap Buffer
    */
    void unmap();
};


//templated bufferObject

//vertex formate
//Vec2f, Vec3f, etc

    
} //end namespace csoh


#endif //__CSOH_GLVERTEXBUFFER_HPP__
