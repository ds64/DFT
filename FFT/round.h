//
//  round.h
//  FFT
//
//  Created by Andrey Bogdanov on 23.12.14.
//  Copyright (c) 2014 Andrey Bogdanov. All rights reserved.
//

#ifndef __FFT__round__
#define __FFT__round__

#include <iostream>

class roundc
{
public:
    static double rounddef(const double & value, const int & power);
    static double roundinc(const double & value, const int & power);
    static double rounded(const double & value, const int & power);
};

#endif /* defined(__FFT__round__) */
