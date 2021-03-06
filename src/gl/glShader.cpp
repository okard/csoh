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
#include <csoh/gl/glShader.hpp>

#include <csoh/Exception.hpp>
#include <iostream>

using namespace csoh;

//TODO Error Handling see http://duriansoftware.com/joe/An-intro-to-modern-OpenGL.-Chapter-2.2:-Shaders.html

//== glShader ================================================================

/**
* Create new OpenGL Shader
*/
glShader::glShader(GLenum type)
{
    //assert that glew is initialized?
    shaderId = glCreateShader(type);
}

/**
* Destructs
*/
glShader::~glShader()
{
    glDeleteShader(shaderId);
}
    
/**
* Compile Shader
*/
void glShader::compile(const char* src)
{
    glShaderSource(shaderId, 1, &src, NULL);
    glCompileShader(shaderId);
    
    GLint shaderValid;
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &shaderValid);
    if (!shaderValid) 
    {
		GLint log_length = 0;
		glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &log_length);
		
		//char* log = (char*)malloc(log_length);
		//glGetShaderInfoLog(object, log_length, NULL, log);
		
        std::cerr << "Failed to compile: \n" << src << std::endl;
        //TODO get error log
        throw StaticException("Failed to compile shader see stderr for more information");
    }
}

