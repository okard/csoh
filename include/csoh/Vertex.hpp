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
#ifndef __CSOH_VERTEX_HPP__
#define __CSOH_VERTEX_HPP__

namespace csoh {
    
/**
* Available Vertex Formats
*/    
enum VertexFormat
{
    /// Simple vertex 
    SimpleVertex,
    /// Vertex with texture coords
    VertexTexture,
    /// Vertex with texture and normal coords
    VertexTextureNormal,
};


/**
* Simple Vertex Structure
*/
struct SV
{  
    //vertex
    float x, y, z;
};  
    
    
/**
* Vertex Structure with textcoords
*/
struct VT
{  
    //vertex
    float x, y, z;
    //textcoord
    float s0, t0;
};    
    
    
/**
* Vertex Structure with normal and textcoords
*/
struct VNT
{  
    //vertex
    float x, y, z;
    //normal
    float nx, ny, nz;
    //textcoord
    float s0, t0;
};


//triangle
//quads
//lines

//splittet data to shader?

} // end namespace csoh
 
#endif // __CSOH_VERTEX_HPP__