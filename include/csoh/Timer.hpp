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
#ifndef __CSOH_TIMER_HPP__
#define __CSOH_TIMER_HPP__

namespace csoh {

/**
* High Precesion Timer
*/
class Timer
{
private:
    /// is running
    bool running;
    
    
    //TODO use long not float 
    /// Last time value
    long lastTime;
    
public:
    /**
    * Create new Timer
    */
    Timer();
    
    /**
    * Create new Timer
    */
    Timer(bool start);
    
    /**
    * Destructs timer
    */
    ~Timer();
   
    /**
    * Start timer
    */
    void start();
    
    /**
    * Stop timer
    */
    float stop();
    
    /**
    * Reset timer
    */
    void reset();
    
    /**
    * Elapsed time
    */
    long time(bool reset = false);
    
    /**
    * Is the timer running or stopped
    */
    bool isRunning();
};

} //end namespace csoh


#endif // __CSOH_TIMER_HPP__
