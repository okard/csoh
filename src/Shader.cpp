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
#include <csoh/Shader.hpp>

#include <csoh/ScopePtr.hpp>
#include <csoh/Utils.hpp>

using csoh::ShaderProgram;

/**
* Create a new ShaderProgram with Vertex and Fragment Pointer
*/
ShaderProgram::ShaderProgram()
    : vertex(GL_VERTEX_SHADER), fragment(GL_FRAGMENT_SHADER)
{
}

/**
* Destruct
*/
ShaderProgram::~ShaderProgram()
{
}

void ShaderProgram::loadFrag(const char* shaderSrc)
{
	glShader shader(GL_FRAGMENT_SHADER);
	shader.compile(shaderSrc);
	shader_.push_back(shader);
	program.attach(&shader);
}

void ShaderProgram::loadFragFromFile(const char* shaderFilename)
{
	csoh::ScopePtr<char> fragmentShader(csoh::readfile(shaderFilename));
	loadFrag(fragmentShader.get());
}


void ShaderProgram::loadVert(const char* shaderSrc)
{
	glShader shader(GL_VERTEX_SHADER);
	shader.compile(shaderSrc);
	shader_.push_back(shader);
	program.attach(&shader);
}

void ShaderProgram::loadVertFromFile(const char* shaderFilename)
{
	csoh::ScopePtr<char> vertexShader(csoh::readfile(shaderFilename));
	loadVert(vertexShader.get());
}
    
void ShaderProgram::link()
{
	program.link();
}

/**
* Use Program now
*/
void ShaderProgram::use()
{
    //TODO Check State before use
    program.use();
}
