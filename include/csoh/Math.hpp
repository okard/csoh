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
#ifndef __CSOH_MATH_HPP__
#define __CSOH_MATH_HPP__

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp> //also to MathFunction Header?
#include <glm/gtx/quaternion.hpp>
//seperate header?
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>


namespace csoh {
    
//=============================================================================
// Utility Functions
//=============================================================================

/**
* Clamp Value 
*/    
template<typename T>
static inline T clamp(T value, T max, T min)
{
    if(value > max)
        return max;
    if(value < min)
        return min;
    return value;
}

namespace math = glm;
typedef math::mat4 Matrix4f;
typedef math::vec2 Vec2f;
typedef math::vec3 Vec3f;
typedef math::vec4 Vec4f;
typedef math::quat Quatf;
    
} //end namespace csoh


#endif // __CSOH_MATH_HPP__
