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
#ifndef __CSOH_GLMESH_HPP__
#define __CSOH_GLMESH_HPP__

#include <csoh/Shader.hpp>

#include <csoh/Vertex.hpp>
#include <csoh/gl/glBufferObject.hpp>
#include <csoh/gl/glTexture.hpp>
#include <csoh/gl/glVertexArray.hpp>

namespace csoh {

/**
* Represents a drawable structure for OpenGL
*/
class glMesh
{
private:
    //Material?
    
    /// Shader Program
    ShaderProgram shaderProg;
    
    /// Vertex Array
    glBufferObject vertexArray;
 
    /// Element Array
    glBufferObject elementArray;

    /// Texture
    glTexture texture;
    
    /// Vertex Array Object
    glVertexArray vao;
    
public:
    
    /**
    * Create a new OpenGL mesh
    */
    glMesh();
    
    /**
    * Destroy OpenGL mesh
    */
    ~glMesh();
    
    //TODO setup
    
    //template <class T> void load(T[] data) {}
    
    //TODO Load data
    //TODO Modify Data
    //TODO Render Data
    
};
    
    

} //end namespace csoh
    
#endif // __CSOH_GLMESH_HPP__
