
#include <csoh/gl/glShaderProgram.hpp>

#include <csoh/gl/glShader.hpp>

#include <csoh/Exception.hpp>

#include <iostream>

using namespace csoh;

/**
* Create new opengl shader program
*/
glProgram::glProgram()
{
    progId = glCreateProgram();
}

/**
* Destructs opengl shader program
*/
glProgram::~glProgram()
{
    glDeleteProgram(progId);
}

/**
* Attach a shader to program
*/
void glProgram::attach(glShader* shader)
{
    glAttachShader(progId, shader->shaderId);
}

/**
* Detach shader from program
*/
void glProgram::detach(glShader* shader)
{
     glDetachShader(progId, shader->shaderId);
}

/**
* Link shader
*/
void glProgram::link()
{
    glLinkProgram(progId);
    
    GLint programValid;
    
    glGetProgramiv(progId, GL_LINK_STATUS, &programValid);
    if (!programValid) 
    {
        std::cerr << "Failed to link shade program:\n" << std::endl;
        //TODO get error log
        throw StaticException("Failed to link shader program see stderr for more information");
    }
}

/**
* Use shader
*/
void glProgram::use()
{
    glUseProgram(progId);
}
