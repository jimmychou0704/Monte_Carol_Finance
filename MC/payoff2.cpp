//
//  payoff2.cpp
//  Monte_Carol_Fincace


#include "payoff2.hpp"

#include "payOff2.hpp"

/***********************************************
 
                payOff_bridge
 
 ***********************************************/

//constructor
payOff_bridge::payOff_bridge(const payOff& inner){
    
    PayOff_ptr = inner.clone();
    
}


//copy constructor
payOff_bridge::payOff_bridge(const payOff_bridge& origin){
    
    PayOff_ptr = origin.PayOff_ptr->clone();
    
}

//assignment constructor
payOff_bridge& payOff_bridge::operator=(const payOff_bridge& origin){
    delete PayOff_ptr;
    PayOff_ptr = origin.PayOff_ptr->clone();
    return *this;
}


double payOff_bridge::operator()(double spot)const {
    
    return (*PayOff_ptr)(spot);
}


/***********************************************
 
                payOff_put
 
 ***********************************************/
 


double payOff_put::   operator()(double spot) const{
    
    
    return std::max(strike-spot, 0.0);
    
    
}

//When we declare an option object, we plug in a payOff object.
//Inside the option oject, it can clone a payoff object for its own,
//so that it won;t be affected by modification of payOff file.

payOff* payOff_put:: clone() const {
    
    return new payOff_put(*this);
    
}


/***********************************************
 
                payOff_call
 
 ***********************************************/

double payOff_call:: operator()(double spot) const{
    
    return std::max(spot-strike, 0.0);
}

payOff* payOff_call:: clone() const {
    
    return new payOff_call(*this);
}