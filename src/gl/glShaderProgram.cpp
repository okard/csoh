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

#include <csoh/gl/glShaderProgram.hpp>

#include <csoh/gl/glShader.hpp>
#include <csoh/Exception.hpp>

#include <iostream>

using namespace csoh;

/**
* Create new opengl shader program
*/
glShaderProgram::glShaderProgram()
{
    progId = glCreateProgram();
}

/**
* Destructs opengl shader program
*/
glShaderProgram::~glShaderProgram()
{
    glDeleteProgram(progId);
}

/**
* Attach a shader to program
*/
void glShaderProgram::attach(glShader* shader)
{
    glAttachShader(progId, shader->shaderId);
}

/**
* Detach shader from program
*/
void glShaderProgram::detach(glShader* shader)
{
     glDetachShader(progId, shader->shaderId);
}

/**
* Link shader
*/
void glShaderProgram::link()
{
    glLinkProgram(progId);
    
    GLint programValid;
    
    glGetProgramiv(progId, GL_LINK_STATUS, &programValid);
    if (!programValid) 
    {
		//glGetProgramiv(object, GL_INFO_LOG_LENGTH, &log_length);
		//glGetProgramInfoLog(object, log_length, NULL, log);
		
        std::cerr << "Failed to link shade program:\n" << std::endl;
        //TODO get error log
        throw StaticException("Failed to link shader program see stderr for more information");
    }
}

/**
* Use shader
*/
void glShaderProgram::use()
{
    glUseProgram(progId);
}
