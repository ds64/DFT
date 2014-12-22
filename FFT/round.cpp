//
//  round.cpp
//  FFT
//
//  Created by Andrey Bogdanov on 23.12.14.
//  Copyright (c) 2014 Andrey Bogdanov. All rights reserved.
//

#include "round.h"
#include <math.h>
#include <tgmath.h>

double roundc::rounddef(double value, int power)
{
    double res = (long)(value*pow(2,power));
    return res/pow(2,power);
}

double roundc::roundinc(double value, int power)
{
    double res = (long)(value*pow(2,power));
    long tmp = (long)res % 10;
    if (tmp % 2 == 0)
    {
        if (value > 0)
        {
            res++;
        }
        else
            res--;
    }
    return res/pow(2,power);
}

double roundc::rounded(double value, int power)
{
    return (round(value*pow(2,power)))/pow(2,power);
}

