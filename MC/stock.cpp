//
//  stock.cpp
//  Monte_Carol_Fincace


#include "stock.hpp"
#include "random.hpp"


/*
double GBM_one_spot::operator()(double T, int num_of_interval)const {
    double z = box_muller();
    return S_0*exp((mu - 0.5* sigma*sigma)*T+sigma*sqrt(T)*z);
    
    
    
}
*/


double GBM_one_spot::operator()(double T, int num_of_interval)const {
    double z = box_muller();
    return S_0*exp((mu - 0.5* sigma*sigma)*T+sigma*sqrt(T)*z);
    
}







double GBM::operator()(double T, int num_of_interval) const {
     double price  = GBM_rv(T, num_of_interval, mu, S_0, sigma).back();
     
    
     return price;
}
    
