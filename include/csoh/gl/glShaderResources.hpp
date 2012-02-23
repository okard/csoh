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
#ifndef __CSOH__GLSHADERRESOURCES_HPP__
#define __CSOH__GLSHADERRESOURCES_HPP__

namespace csoh {

//Basic Shader 
    
/**
* Base Vertex Shader
*/
const char* BaseVertexShader = "void main(void) \
                                { \
                                    gl_Position     = gl_ModelViewProjectionMatrix * gl_Vertex; \
                                    gl_TexCoord[0]  = gl_MultiTexCoord0; \
                                }";

/*
#version 140
 
uniform Transformation {
    mat4 projection_matrix;
    mat4 modelview_matrix;
};
 
in vec3 vertex;
 
void main() {
    gl_Position = projection_matrix * modelview_matrix * vec4(vertex, 1.0);
}
 
*/

/**
* Simple Fragment Shader with 1 Texture
*/
const char* SimpleFragmentShader1T = "uniform sampler2D texSampler; \
                                      \
                                      void main(void) \
                                      { \
                                           gl_FragColor = texture2D(texSampler, vec2(gl_TexCoord[0])); \
                                      }";
    
/*
VertexShader:

void main(void)
{
 gl_Position     = gl_ModelViewProjectionMatrix * gl_Vertex;
 gl_TexCoord[0]  = gl_MultiTexCoord0;
}

Fragment Shader:

uniform sampler2D texSampler;
 
void main(void)
{
 gl_FragColor = texture2D(texSampler, vec2(gl_TexCoord[0]));
}

*/



} // end namespace csoh


#endif // __CSOH__GLSHADERRESOURCES_HPP__
