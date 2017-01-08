//
//  payoff2.cpp
//  Monte_Carol_Fincace


#include "payoff2.hpp"

#include "payOff2.hpp"


double payOff_put::   operator()(double spot) const{
    
    
    return std::max(strike-spot, 0.0);
    
    
}

//When we declare an option object, we plug in a payOff object.
//Inside the option oject, it can clone a payoff object for its own,
//so that it won;t be affected by modification of payOff file.

payOff2* payOff_put:: clone() const {
    
    return new payOff_put(*this);
    
}




double payOff_call:: operator()(double spot) const{
    
    return std::max(spot-strike, 0.0);
}

payOff2* payOff_call:: clone() const {
    
    return new payOff_call(*this);
}