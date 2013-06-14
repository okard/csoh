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
#ifndef __CSOH_MESH_HPP__
#define __CSOH_MESH_HPP__

#include <csoh/Math.hpp>
#include <csoh/gl/glMesh.hpp>


namespace csoh {
    
/**
* Represents a Mesh
*/    
class Mesh
{
private:
    /// OpenGL Mesh Format
    glMesh mesh;
    
    //Material
    Material mat_;
    
    
    //TODO move this to model
    //model refs mesh to position 
    //a mesh is static
    //think about bone animations
    
    // Positioning and so on
    Vec3f position_; //position in 3d world
    Quatf rotation_; //rotation
    Vec3f size_;	 //size and scaling	0,0,0 bottm left front egde size_(x,y,z) 
					 //the upper right back point spanning a block
    
    //shader bindings?
    
public:
    
    //load vertexes?
    //directly?
    //index elements?
    
    //set texture
    
    //load(
    
    /**
    * Render Mesh
    */
    void render();
    
    //get Material
};
    
// Mesh<VertexFormat>

    
} //end namespace csoh



#endif // __CSOH_MESH_HPP__
