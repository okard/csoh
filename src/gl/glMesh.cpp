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
#include <csoh/gl/glMesh.hpp>

#include <csoh/gl/GL.hpp>

using csoh::glMesh;

/**
* Create a new OpenGL mesh
*/
glMesh::glMesh()
    :  vertexArray(GL_ARRAY_BUFFER), elementArray(GL_ELEMENT_ARRAY_BUFFER)
{
}

/**
* Destroy OpenGL mesh
*/
glMesh::~glMesh()
{
}


/**
* Load data from memory
*/
void glMesh::loadData(VertexFormat format, const void* data, int length)
{
    //length vs count
    
    vao.bind();
    vertexArray.bind();
    
    //.setBufferData(const void *bufferData, GLsizei bufferSize, GLenum usage);
    
    
    // 0 , 3 floats, not normalized, vertex size (-xyz?), start 0)
    //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), 0)
    //glColorPointer(4, GL_FLOAT, sizeof(VertexFormat), pos(Vertex.r))
    //glTexCoordPointer(3,  GL_Float, sizeof(VertexFormat),  pos(tx));
    
    elementArray.bind();
    
    //   glEnableClientState(GL_VERTEX_ARRAY);
    //glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    
    // bind vbos to attrib index
    // bind attrib index to shader attrib
    // glEnableVertexAttribArray(0);
    // glBindAttribLocation(shaderprogram, 0, );
 

    //index data?
    //predefined element strategies
    //triangles mesh
    // strip -> 123, 234, 345, 456, 567, ...
}

/**
* Render Mesh
*/
void glMesh::render()
{
    vao.bind();
    //glDrawElements(GL_TRIANGLE_STRIP,  4, GL_UNSIGNED_SHORT,  (void*)0);
    
    //glDrawArrays(GL_QUADS, 0, buffer.length);  //  Ausgabe
    
    
}