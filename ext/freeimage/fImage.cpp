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
#include "fImage.hpp"

#include <csoh/Exception.hpp>

using csoh::fImage;
using csoh::StaticException;


/// Read in image
void fImage::read(const char* filename)
{
    dib = 0;
    bits = 0;
    
    //image format
    FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;
    
    //check the file signature and deduce its format
    fif = FreeImage_GetFileType(filename, 0);
    //if still unknown, try to guess the file format from the file extension
    if(fif == FIF_UNKNOWN) 
        fif = FreeImage_GetFIFFromFilename(filename);
    //if still unkown, return failure
    if(fif == FIF_UNKNOWN)
        throw StaticException("FreeImage can't detect image file type");

    //check that the plugin has reading capabilities and load the file
    if(FreeImage_FIFSupportsReading(fif))
        dib = FreeImage_Load(fif, filename);
    
    //if the image failed to load, return failure
    if(!dib)
        throw StaticException("FreeImage can't read image file");

    //retrieve the image data
    bits = FreeImage_GetBits(dib);
    //get the image width and height
    mWidth = FreeImage_GetWidth(dib);
    mHeight = FreeImage_GetHeight(dib);
    
    //FreeImage_GetBPP(FIBITMAP *dib);
    
    //if this somehow one of these failed (they shouldn't), return failure
    if((bits == 0) || (mWidth == 0) || (mHeight == 0))
        throw StaticException("FreeImage can't read image file");
}

/// Clear Memory
void fImage::clear()
{
    //TODO clear only when it is loaded
    
    //Free FreeImage's copy of the data
    FreeImage_Unload(dib);
}

/// Get Memory
inline void* fImage::data() const
{
    return bits;
}


//FreeImage init?

/*
bool TextureManager::LoadTexture(const char* filename, const unsigned int texID, GLenum image_format, GLint internal_format, GLint level, GLint border)
{
    //OpenGL's image ID to map to
    GLuint gl_texID;

    //if this texture ID is in use, unload the current texture
    if(m_texID.find(texID) != m_texID.end())
        glDeleteTextures(1, &(m_texID[texID]));

    //generate an OpenGL texture ID for this texture
    glGenTextures(1, &gl_texID);
    //store the texture ID mapping
    m_texID[texID] = gl_texID;
    //bind to the new texture ID
    glBindTexture(GL_TEXTURE_2D, gl_texID);
    //store the texture data for OpenGL use
    glTexImage2D(GL_TEXTURE_2D, level, internal_format, width, height,
        border, image_format, GL_UNSIGNED_BYTE, bits);
}
*/
