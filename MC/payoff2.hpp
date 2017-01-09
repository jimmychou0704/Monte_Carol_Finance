//
//  payoff2.hpp
//  Monte_Carol_Fincace


#ifndef payoff2_hpp
#define payoff2_hpp


#include <stdio.h>
#include <iostream>

class payOff{
public:
    
    
    //payOff(double s){}; Here we don't have constructor taking argumant here, if there is,
    // in the derived class constructor, we need to do payOff_put(double s): payOff(s), strike(s){};
    
    
    
    virtual double operator()(double spot) const = 0;   //overload the operator (), spot is the stock price on expire day.
    
    virtual payOff* clone() const = 0;
    
    virtual ~payOff(){};
    
private:
    
    double strike;
    
    
    
};


class payOff_bridge{
    
public:
    //constructor
    payOff_bridge(const payOff& innerPayOff);
    
    //assignment constructor
    payOff_bridge(const payOff_bridge& orignal);
    
    //copy constructor
    payOff_bridge& operator=(const payOff_bridge&);
    
    double operator()(double spot) const;
    
    
private:
    payOff* PayOff_ptr;
};


class payOff_put: public payOff{
public:
    
    payOff_put(double s): strike(s){};
    virtual double operator()(double spot) const;
    virtual payOff* clone() const;
    virtual ~payOff_put(){};
private:
    double strike;
    
};


class payOff_call: public payOff{
public:
    
    payOff_call(double s): strike(s){};
    virtual double operator()(double spot) const;
    virtual payOff* clone() const;
    virtual ~payOff_call(){};
private:
    double strike;
    
};




#endif /* payoff2_hpp */
