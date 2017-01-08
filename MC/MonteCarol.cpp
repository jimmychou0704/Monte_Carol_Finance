//
//  MonteCarol.cpp
//  Monte_Carol_Fincace
//


#include "MonteCarol.hpp"



double monte_carol( const option & theOption,        //type of option, call or put
                   
                   const stock& stock,               // model of stock price model, ex, BGM of Jump diffusion..etc
                   double S_0,                       // stock price now
                   double vol,                       // Sigma
                   double r,                         // interest rate
                   unsigned long number_of_paths     // compute the expectation of future stock price,
//generate lot of random numbers, and take average
)
{
    double T = theOption.get_expire();
    
    
    double sum = 0;
    
    //simulate numberOfPaths future stock prices
    
    srand((int) time(0));
    for (int i = 0; i< number_of_paths; i++){
        
        double future_spot = stock(T);
        
        sum += theOption.option_pay_off(future_spot);
    }
    
    // take the average of these stimulating results
    double mean = sum/number_of_paths;
    
    //return the mean after discounted the future value
    return exp(-r*T)*mean;
    }
