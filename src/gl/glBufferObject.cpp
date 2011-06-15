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
#include <csoh/gl/glBufferObject.hpp>

using csoh::glBufferObject;

/**
* Create new Vertex Buffer Object
*/
glBufferObject::glBufferObject(GLenum type)
    : type(type)
{
    //check for render context
    
    glGenBuffers(1, &vboId);
    
    //TODO check for GL_ARRAY_BUFFER,GL_ELEMENT_ARRAY_BUFFER, GL_PIXEL_PACK_BUFFER, or GL_PIXEL_UNPACK_BUFFER.          
}
    
/**
* Destructs Vertex Buffer Object
*/
glBufferObject::~glBufferObject()
{
    glDeleteBuffers(1, &vboId );
}

/**
* Bind Vertex Buffer
*/
void glBufferObject::bind()
{
    //TODO Check if already binded
    glBindBuffer(type, vboId);
}

/**
* Set Buffer Data
*/
void glBufferObject::setBufferData(const void *bufferData, GLsizei bufferSize, GLenum usage)
{          
    bind();
    glBufferData(type, bufferSize, bufferData, usage);
}

/**
* Update Buffer Data
*/
void glBufferObject::updateBufferData(GLintptr  offset, const void *bufferData, GLsizei bufferSize)
{
    bind();
    glBufferSubData(type, offset,  bufferSize,  bufferData);
}

/**
* Map Buffer
* GL_READ_ONLY, GL_WRITE_ONLY, GL_READ_WRITE
*/
void* glBufferObject::map(GLenum  access)
{
    bind();
    return glMapBuffer(type, access);
}

/**
* Unmap Buffer
*/
void glBufferObject::unmap()
{
    bind();
    glUnmapBuffer(type);
}

    
    
    
