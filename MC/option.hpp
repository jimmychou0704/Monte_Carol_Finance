//
//  option.hpp
//  Monte_Carol_Fincace
//

#include <iostream>
#include "payoff2.hpp"

#ifndef option_h
#define option_h


//option object. contains the information of strike and expire date.
//It is put or call (or something else) depends on what we plug into payOff2

/*
class option{
    
    double strike;
    double expire;
    payOff2& the_payoff;
public:
    
    option(const payOff2&, double strike, double expire,
           double spot);
    double option_pay_off(double spot) const;
    virtual double get_strike();
    virtual double get_expire() const ;
    
    
};
*/

class option{
    
public:
    virtual double option_pay_off(double spot) const = 0;
    virtual double get_expire() const = 0;

    //virtual ~option();
    
};



class vanilla_option: public option{
public:
    vanilla_option(payOff2& thePayOff_, double expiry_);
    
    virtual double option_pay_off(double spot) const;
    virtual double get_expire() const;
    virtual ~vanilla_option();
    
    //copy constructor
    vanilla_option(const vanilla_option& origin);
    
    //assignment constructor
    vanilla_option& operator=(const vanilla_option& orign);
    
    double expiry;
private:
    
    
    payOff2* payOffPtr;
    
    //payOff2& thePayOff;     //thePayOff is an abstract class, co here must be reference
};









#endif /* option_h */
