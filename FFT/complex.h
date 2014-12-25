//
//  complex.h
//  FFT
//
//  Created by Andrey Bogdanov on 22.12.14.
//  Copyright (c) 2014 Andrey Bogdanov. All rights reserved.
//

#ifndef __FFT__complex__
#define __FFT__complex__

#include <iostream>

class complex
{
public:
    complex();
    complex(const double & r);
    complex(const double & r, const double & i);
    ~complex();
    
    double get_re();
    double get_im();
    
    void set_re(const double & re);
    void set_im(const double & im);
    
    void print();
    void print_re();
    
    complex operator+(complex * c2)
    {
        complex res;
        res.set_re(this->get_re() + c2->get_re());
        res.set_im(this->get_im() + c2->get_im());
        
        return res;
    }
    
    complex operator-(complex * c2)
    {
        complex res;
        res.set_re(this->get_re() - c2->get_re());
        res.set_im(this->get_im() - c2->get_im());
        
        return res;
    }
    
    complex operator*(complex * c2)
    {
        complex res;
        res.set_re(this->get_re()*c2->get_re() - this->get_im()*c2->get_im());
        res.set_im(this->get_im()*c2->get_re() + this->get_re()*c2->get_im());
        
        return res;
    }
    
    complex operator/(complex * c2)
    {
        complex res;
        res.set_re((this->get_re()*c2->get_re() + this->get_im()*c2->get_im())/
                   (c2->get_re()*c2->get_re() + c2->get_im()*c2->get_im()));
        res.set_im((this->get_im()*c2->get_re() - this->get_re()*c2->get_im())/
                   (c2->get_re()*c2->get_re() + c2->get_im()*c2->get_im()));
        
        return res;
    }
    
private:
    double Re;
    double Im;
};

#endif /* defined(__FFT__complex__) */
