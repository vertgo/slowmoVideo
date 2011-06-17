/*
This file is part of slowmoVideo.
Copyright (C) 2011  Simon A. Eugster (Granjow)  <simon.eu@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
*/

#include "abstractFrameSource_sV.h"

AbstractFrameSource_sV::AbstractFrameSource_sV(const Project_sV *project) :
    m_project(project),
    m_initialized(false)
{
}

AbstractFrameSource_sV::~AbstractFrameSource_sV()
{

}

void AbstractFrameSource_sV::initialize()
{
    m_initialized = true;
}
bool AbstractFrameSource_sV::initialized()
{
    return m_initialized;
}


float AbstractFrameSource_sV::fps() const throw(Div0Exception)
{
    int num = frameRateNum();
    int den = frameRateDen();
    if (den == 0) {
        throw Div0Exception();
    }
    return float(num)/float(den);
}
