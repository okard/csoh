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
#ifndef __CSOH_SHADER_HPP__
#define __CSOH_SHADER_HPP__

#include <csoh/gl/glShader.hpp>

namespace csoh {

/**
* A Complete Shader Program
*/
class ShaderProgram
{
private:
	///multiple shader?
	//List<glShader> shader;
	
    /// Vertex Shader
    glShader vertex;
    /// Fragment Shader
    glShader fragment;
    /// Shader Program
    glProgram program;
    
    //TODO Multiple Shader?
        
public:
    /// Create new Shader
    ShaderProgram();
    
    /// Destruct shader
    ~ShaderProgram();
    
    /// Load Shader from Memory
    //TODO fixit to use multiple vertex fragment shader
    void load(const char* vertex, const char* fragment);
    
    /// Load Shader from File
    //TODO fixit to use multiple vertex fragment shader
    void loadFromFile(const char* vertexShaderFile, const char* fragmentShaderFile);
    
    /// Activate Shader Program
    void use();
    


	//attrib 

    //get list with parameters?
    //TODO Parameter Handling
        
};
    
    
} // end namespace csoh

#endif // __CSOH_SHADER_HPP__
