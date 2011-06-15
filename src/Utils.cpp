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
#include <csoh/Utils.hpp>

#include <iostream>
#include <fstream>


using std::filebuf;
using std::ifstream;

namespace csoh
{

/**
* Read in a file, delete after usage
*/
char* readfile(const char* filename)
{
    filebuf *pbuf;
    ifstream filestr;
    
    //open file
    filestr.open(filename);
    // get pointer to associated buffer object
    pbuf=filestr.rdbuf();
    std::streampos size =pbuf->pubseekoff (0, std::ios::end, std::ios::in);
    pbuf->pubseekpos (0, std::ios::in);

    // allocate memory to contain file data
    char* buffer=new char[size];
    // get file data  
    pbuf->sgetn (buffer,size);

    filestr.close();
    
    return buffer;
}

} //end namespace csoh