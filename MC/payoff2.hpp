//
//  payoff2.hpp
//  Monte_Carol_Fincace


#ifndef payoff2_hpp
#define payoff2_hpp


#include <stdio.h>
#include <iostream>

class payOff2{
public:
    
    
    //payOff(double s){}; Here we don't have constructor taking argumant here, if there is,
    // in the derived class constructor, we need to do payOff_put(double s): payOff(s), strike(s){};
    
    
    
    virtual double operator()(double spot) const = 0;   //overload the operator (), spot is the stock price on expire day.
    
    virtual payOff2* clone() const = 0;
    
    virtual ~payOff2(){};
    
private:
    
    double strike;
    
    
    
};

class payOff_put: public payOff2{
public:
    
    payOff_put(double s): strike(s){};
    virtual double operator()(double spot) const;
    virtual payOff2* clone() const;
    virtual ~payOff_put(){};
private:
    double strike;
    
};


class payOff_call: public payOff2{
public:
    
    payOff_call(double s): strike(s){};
    virtual double operator()(double spot) const;
    virtual payOff2* clone() const;
    virtual ~payOff_call(){};
private:
    double strike;
    
};




#endif /* payoff2_hpp */
