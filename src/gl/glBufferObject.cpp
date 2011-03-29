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
    glBindBuffer(type, vboId);
}


/**
* Set Buffer Data
*/
void glBufferObject::setBufferData(const void *bufferData, GLsizei bufferSize)
{
    //TODO Make more dynamic buffer mode? static, dynamic
    
    // GL_STREAM_DRAW, GL_STREAM_READ, GL_STREAM_COPY, 
    // GL_STATIC_DRAW, GL_STATIC_READ, GL_STATIC_COPY, 
    // GL_DYNAMIC_DRAW, GL_DYNAMIC_READ, or GL_DYNAMIC_COPY.
                
    glBufferData(type, bufferSize, bufferData, GL_STATIC_DRAW);
}


// glVertexPointer(4, GL_FLOAT, STRIDE, POS_OFFSET);
// glColorPointer(4, GL_FLOAT, STRIDE, COL_OFFSET);
// glDrawElements
// glDrawArrays


