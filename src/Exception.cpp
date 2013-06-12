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
#include <csoh/Exception.hpp>

#include <cstdarg>
#include <cstdio>

using namespace csoh;

/**
* Constructor
*/
FormatException::FormatException(const char* msg, ...)
{
	va_list argument_list;
	va_start(argument_list, msg);
	
	int len = vsnprintf(msg_, buf_size - 2, msg, argument_list);  
	if(len < 0 || len > buf_size - 2)  
	{
		len = buf_size - 2;
	}
	msg_[len] = '\0';

	va_end(argument_list);
}

FormatException::~FormatException()
{
}

const char* FormatException::what() const throw()
{
	return msg_;
}


