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
#ifndef __CSOH_GLTEXTURE_HPP__
#define __CSOH_GLTEXTURE_HPP__

#include <csoh/Image.hpp>
#include <csoh/gl/OpenGL.hpp>

namespace csoh {
 
/**
* OpenGL 2D Texture 
*/
class glTexture
{
private:
    GLuint texId;
     
public:
    /**
    * Create a new OpenGL Texture
    */
    glTexture();
    
    /**
    * Destructs Texture
    */
    ~glTexture();
    
    /**
    * Bind Texture
    */
    void bind();
    
    /**
    * Bind to specific texture layer
    * e.g. GL_TEXTURE0
    */
    void bind(GLenum texture);
 
    /**
    * Load from Image
    */
    void load(const Image* img);
    
    /**
    * Clears the texture
    */
    void clear();
    
    //set(void[])
    //config 
    //mipmap handling
    
};
    
} //end namespace csoh


#endif // __CSOH_GLTEXTURE_HPP__
