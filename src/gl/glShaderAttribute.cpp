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
#include <csoh/gl/glShaderAttribute.hpp>

#include <csoh/Exception.hpp>
#include <csoh/gl/glShaderProgram.hpp>

using namespace csoh;

/**
* Create a new OpenGL Texture
*/
glShaderAttribute::glShaderAttribute()
	: attribLoc_(-1)
{
}
    
/**
* Destructs Texture
*/
glShaderAttribute::~glShaderAttribute()
{
}
   
void glShaderAttribute::bind(glShaderProgram& shader, const char* name)
{
	attribLoc_ = glGetAttribLocation(shader.progId, name);

	if (attribLoc_ == -1) 
		throw StaticException("Can't bind attribute");
}


void glShaderAttribute::enable()
{
	glEnableVertexAttribArray(attribLoc_);
}

void glShaderAttribute::disable()
{
	glDisableVertexAttribArray(attribLoc_);
}

/*
  glVertexAttribPointer(
    attribute_v_color, // attribute
    3,                 // number of elements per vertex, here (R,G,B)
    GL_FLOAT,          // the type of each element
    GL_FALSE,          // take our values as-is
    0,                 // no extra data between each position
    0                  // offset of first element
  );

*/
