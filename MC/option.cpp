//
//  option.cpp
//  Monte_Carol_Fincace
//


#include <stdio.h>
#include "option.hpp"

/*

double option:: get_expire() const {
    return  expire;
}

//double option_pay_off(double spot) const;

double option::option_pay_off(double spot) const{
    return the_payoff(spot);
}

 */

vanilla_option::vanilla_option(const payOff_bridge& thePayOff_, double expiry_):  expiry(expiry_), thePayOff(thePayOff_){
};

double  vanilla_option::get_expire() const {return expiry;}


//(*payOffPtr) is a payOff instance
//so (*payOffptr)( ) will give the payoff (ex. K - S_T if it is a call)
//remember we overload the operator()

double vanilla_option:: option_pay_off(double spot) const {
    return thePayOff(spot);
    
}
/*
vanilla_option::~vanilla_option() {
    delete payOffPtr;
}


//copy constructor
vanilla_option::vanilla_option(const vanilla_option& origin){
    
    expiry = origin.get_expire();
    payOffPtr = origin.payOffPtr->clone();
    
}


//assignment constructor
vanilla_option& vanilla_option:: operator=(const vanilla_option& origin){
    expiry = origin.get_expire();
    delete payOffPtr;
    payOffPtr = origin.payOffPtr->clone();
    
    return (*this);
    
}
*/

