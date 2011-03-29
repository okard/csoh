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
#include <csoh/gl/glVertexBuffer.hpp>

using csoh::glVertexBuffer;

/**
* Create new Vertex Buffer Object
*/
glVertexBuffer::glVertexBuffer()
{
    glGenBuffers(1, &vboId);
}
    
/**
* Destructs Vertex Buffer Object
*/
glVertexBuffer::~glVertexBuffer()
{
    glDeleteBuffers(1, &vboId );
}

/**
* Bind Vertex Buffer
*/
void glVertexBuffer::bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, vboId);
}


/**
* Set Buffer Data
*/
void glVertexBuffer::setBufferData(const void *bufferData, GLsizei bufferSize)
{
    //TODO Make more dynamic GL_ARRAY_BUFFER / GL_ELEMENT_ARRAY_BUFFER
    glBufferData(GL_ARRAY_BUFFER, bufferSize, bufferData, GL_STATIC_DRAW);
}

//glDrawArrays

//glBufferDataARB(GL_ARRAY_BUFFER, size, NULL, GL_STATIC_DRAW);
//glBufferDataARB
//render function?
// glVertexPointer(4, GL_FLOAT, STRIDE, POS_OFFSET);
// glColorPointer(4, GL_FLOAT, STRIDE, COL_OFFSET);
// glDrawElements


