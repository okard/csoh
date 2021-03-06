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
#include <csoh/Mesh.hpp>

using csoh::Mesh;


//glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(0.0, 0.0, -4.0));

/**
* Render Mesh
*/
void Mesh::render()
{
	Matrix4f modelMatrix(1.0f); //calculate from properties?
	modelMatrix = math::translate(modelMatrix, position_);
	modelMatrix = math::scale(modelMatrix, size_);	
	modelMatrix *= math::toMat4(rotation_);
	
	//Material/Shader binding
	//set uniform projection
	//set uniform view
	//set uniform model
	
	//set attrib vertexes
	//set attrib element indexes
	
	//draw call
    mesh.render();
}
