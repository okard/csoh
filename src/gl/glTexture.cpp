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
#include <csoh/gl/glTexture.hpp>

using csoh::Image;
using csoh::glTexture;


/**
* Create a new OpenGL Texture
*/
glTexture::glTexture()
{
    //Generate Texture ID
    glGenTextures(1, &texId);
}

/**
* Destructs Texture
*/
glTexture::~glTexture()
{
    glDeleteTextures(1, &texId);
}

/**
* Bind Texture
*/
void glTexture::bind()
{
    //TODO Make GL Texture Type dynamic
    glBindTexture(GL_TEXTURE_2D, texId);
}

/**
* Bind to specific texture layer
* e.g. GL_TEXTURE0
*/
void glTexture::bind(GLenum texture)
{
    glActiveTexture(texture);
    bind();
}

/**
* Load from Image
* Binds texture automatically
*/
void glTexture::load(const Image* img)
{
    bind();

    //TODO Check if img is valid
    //TODO prepare parameter
    
    GLint mipmapLevel = 0;
    GLint internalFormat = GL_RGB8;
    GLint border = 0;
    GLenum format =  GL_BGR;
    GLenum type = GL_UNSIGNED_BYTE;
    
    //for texture parameter
    //glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);  
    //glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);   
    
    //set texture data
    glTexImage2D(GL_TEXTURE_2D, mipmapLevel, internalFormat, img->width(), img->height(), border, format, type, img->data());  
}


/**
* Clears the texture
*/
void glTexture::clear()
{
    
}



   