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
#ifndef __CSOH_GLSHADERPROGRAM_HPP__
#define __CSOH_GLSHADERPROGRAM_HPP__

#include <csoh/gl/OpenGL.hpp>

namespace csoh {
	
class glShader;

/**
* OpenGL Shader Program
*/
class glShaderProgram
{
	friend class glShaderUniform;
	friend class glShaderAttribute;
	    
private:
    /// Program Id
    GLint progId;
    
    ///TODO Internal State tracker? Empty, Pending, Valid
    
public:
    /**
    * Create new opengl shader program
    */
    glShaderProgram();
    
    /**
    * Destructs opengl shader program
    */
    ~glShaderProgram();
    
    /**
    * Attach a shader to program
    */
    void attach(glShader* shader);
    
    /**
    * Detach shader from program
    */
    void detach(glShader* shader);
    
    /**
    * Link shader
    */
    void link();
    
    /**
    * Use shader
    */
    void use();
    
    
    //debug print out all attributes and uniforms available
    //glGetProgrami
    //GL_ACTIVE_ATTRIBUTES
    //GL_ACTIVE_ATTRIBUTE_MAX_LENGTH
    //GL_ACTIVE_UNIFORMS
    //GL_ACTIVE_UNIFORM_MAX_LENGTH
    //glGetActiveAttrib
    //glGetActiveUniform
};

}//end namespace csoh

#endif
