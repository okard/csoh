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
#include <csoh/gl/glShaderProgram.hpp>

#include <vector>

namespace csoh {

/**
* A Complete Shader Program
*/
class ShaderProgram
{
private:
	///multiple shader?
	//List<glShader> shader;
	std::vector<glShader> shader_;
	
    /// Vertex Shader
    glShader vertex;
    /// Fragment Shader
    glShader fragment;
    /// Shader Program
    glShaderProgram program;
    
    //TODO Multiple Shader?
    
    //save binded paramters for use call to reset?
        
public:
    /// Create new Shader
    ShaderProgram();
    
    /// Destruct shader
    ~ShaderProgram();
    
    
    void loadFrag(const char* shaderSrc);
    void loadFragFromFile(const char* shaderFilename);
    
    void loadVert(const char* shaderSrc);
    void loadVertFromFile(const char* shaderFilename);
    
    
    /// link shader
    void link();
        
    /// Activate Shader Program
    void use(); 

    //get list with parameters?
    //TODO Parameter Handling
        
};
    
    
} // end namespace csoh

#endif // __CSOH_SHADER_HPP__
