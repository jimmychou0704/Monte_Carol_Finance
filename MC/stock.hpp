//
//  stock.hpp
//  Monte_Carol_Fincace
//
//  Created by Chih Chi Chou on 12/31/16.
//  Copyright © 2016 C Chou. All rights reserved.
//

#ifndef stock_hpp
#define stock_hpp

#include <stdio.h>
#include <iostream>
#include "random.hpp"


//return stock price at T


//base class
class stock{
public:
    
    virtual double operator()(double T,
                              int num_of_interval = 100
                              ) const = 0;
    
    /*
    virtual double operator()(double T
                              ) const = 0;
    */
    //virtual double price_of_stcok(double T) const = 0;
    
private:
    double S_0;
    double mu;      //return rate
    double sigma;    //variance of the sock
    
    
    
};


//Geometirc Brownian motion I, just give the sopt price at T
//num_of_inteval is irrelevant here since we only care wabout "ont spot"
//when we use it, we don't need to pligin to it, it's implicitly set into 100
class GBM_one_spot: public stock{
public:
    GBM_one_spot(double mu_, double sigma_, double S_0_):mu(mu_), sigma(sigma_), S_0(S_0_){};
    //virtual double operator()(double T, int num_of_interval) const;
    virtual double operator()(double T, int num_of_interval = 100) const;
  
private:
    double mu;
    double sigma;
    double S_0;
    
};





//Geometric Brownian motion II, gives stock price at each specific point in the interval [0,T]
class GBM : public stock{
    
public:
    GBM(double mu_,double sigma_ ,double S_0_): mu(mu_), sigma(sigma_), S_0(S_0_){};
    //virtual double price_of_stcok(double T) const;
    
    virtual double operator()(double T,
                              int num_of_interval
                              ) const;
private:
    double S_0;
    double mu;
    double sigma;
    
    
    
    
};

#endif /* stock_hpp */
