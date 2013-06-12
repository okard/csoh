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
#include <csoh/gl/glUniform.hpp>
#include <csoh/gl/glShader.hpp>

#include <csoh/Exception.hpp>

using namespace csoh;


void glUniform::bind(glProgram& shader, const char* name)
{
	uniformLoc_ = glGetUniformLocation(shader.progId, name);
	
	if (uniformLoc_ == -1) 
		throw StaticException("Can't bind uniform");
}

//only ptr types with Vec2f and so on formats
//glUniform{1|2|3|4}{f|i|ui}
//glUniform{1|2|3|4}{f|i|ui}v
//glUniformMatrix{2|3|4|2x3|3x2|2x4|4x2|3x4|4x3}fv
    

void glUniform::set(const Matrix4f mat)
{
	glUniformMatrix4fv(uniformLoc_, 1, GL_FALSE, math::value_ptr(mat));
}
