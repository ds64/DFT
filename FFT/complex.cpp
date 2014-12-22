//
//  complex.cpp
//  FFT
//
//  Created by Andrey Bogdanov on 22.12.14.
//  Copyright (c) 2014 Andrey Bogdanov. All rights reserved.
//

#include <iomanip>
#include "complex.h"

complex::complex(): Re(0.0),
                    Im(0.0)
{
}

complex::complex(double r): Im(0.0)
{
    Re = r;
}

complex::complex(double r, double i)
{
    Re = r;
    Im = i;
}

complex::~complex()
{
}

double complex::get_re()
{
    return Re;
}

double complex::get_im()
{
    return Im;
}

void complex::set_re(double re)
{
    Re = re;
}

void complex::set_im(double im)
{
    Im = im;
}

void complex::print()
{
    std::cout << "Re: " << this->get_re();
    std::cout << " Im: " << this->get_im() << std::endl;
}

void complex::print_re()
{
    std::cout << std::fixed << std::setprecision( 5 )
              << std::setfill( '0' ) << this->get_re() << " ";
    //std::cout << this->get_re();
}