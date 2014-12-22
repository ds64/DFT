//
//  main.cpp
//  FFT
//
//  Created by Andrey Bogdanov on 22.12.14.
//  Copyright (c) 2014 Andrey Bogdanov. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
#include "complex.h"
#include "round.h"

const double N = 8;
int n1 = 10;
int n2 = 12;
int n3 = 16;

complex X[(int)N][(int)N];
complex Y[(int)N][(int)N];

complex X1[(int)N][(int)N];
complex Y1[(int)N][(int)N];

void fill()
{
    int oldi = 0;
    for(int i = 0; i < N; i++)
    {
        if(i % 2 == 0)
            oldi = i;
        for(int j = 0; j < N; j++)
        {
            if(((j% 8) == (oldi%8)) || ((j % 8) == (oldi%8 + 1)))
                X[i][j] = *new complex(1);
            else
                X[i][j] = *new complex(-1);
        }
    }
    
    oldi = 0;
    for(int i = 0; i < N; i++)
    {
        if(i % 2 == 0)
            oldi = i;
        for(int j = 0; j < N; j++)
        {
            if(((j% 8) == (oldi%8)) || ((j % 8) == (oldi%8 + 1)))
                X1[i][j] = *new complex(roundc::rounddef(1,n1));
            else
                X1[i][j] = *new complex(roundc::rounddef(-1,n1));
        }
    }
}

complex FFTfloat(int r, int k)
{
    int n = 0;
    complex res;
    for(n = 0; n < N - 1; n++)
    {
        complex tmp(cos(-2*M_PI*n*k/N), sin(-2*M_PI*n*k/N));
        tmp = tmp*X[r][n];
        res = res+tmp;
    }
    complex part_n(1/N);
    return part_n*res;
}

complex FFT(int r, int k)
{
    int n = 0;
    complex res;
    for(n = 0; n < N - 1; n++)
    {
        complex tmp(roundc::rounddef(cos(-2*M_PI*n*k/N),n2), roundc::rounddef(sin(-2*M_PI*n*k/N),n2));
        tmp = tmp*X1[r][n];
        tmp.set_re(roundc::rounddef(tmp.get_re(),n3));
        tmp.set_re(roundc::rounddef(tmp.get_re(),n3));
        res = res+tmp;
        res.set_re(roundc::rounddef(res.get_re(),n3));
        res.set_re(roundc::rounddef(res.get_re(),n3));
    }
    complex part_n(1/N);
    part_n.set_re(roundc::rounddef(part_n.get_re(),n3));
    part_n.set_re(roundc::rounddef(part_n.get_re(),n3));
    complex final = part_n*res;
    final.set_re(roundc::rounddef(final.get_re(),n3));
    final.set_re(roundc::rounddef(final.get_re(),n3));
    return final;
}

void print_matrix_x()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            X[i][j].print_re();
        }
        std::cout << std::endl << "===================" << std::endl;
    }
}

void print_matrix_x1()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            X1[i][j].print_re();
        }
        std::cout << std::endl << "===================" << std::endl;
    }
}

void print_matrix_y()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            Y[i][j].print_re();
        }
        std::cout << std::endl << "===================" << std::endl;
    }
}

void print_matrix_y1()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            Y1[i][j].print_re();
        }
        std::cout << std::endl << "===================" << std::endl;
    }
}

int main(int argc, const char * argv[])
{
    fill();
    
    std::cout << "Source matrix X: " << std::endl;
    print_matrix_x();
    
    std::cout << "Source matrix X1: " << std::endl;
    print_matrix_x1();
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            Y[i][j] = FFTfloat(i, j);
        }
    }
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            Y[j][i] = FFTfloat(j, i);
        }
    }
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            Y1[i][j] = FFT(i, j);
        }
    }
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            Y1[j][i] = FFT(j, i);
        }
    }
    
    std::cout << "Dest matrix Y: " << std::endl;
    print_matrix_y();
    
    std::cout << "Dest matrix Y1: " << std::endl;
    print_matrix_y1();
    
    return 0;
}
