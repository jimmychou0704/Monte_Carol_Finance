//
//  MonteCarol.hpp
//  Monte_Carol_Fincace
//


#ifndef MonteCarol_hpp
#define MonteCarol_hpp


#include "option.hpp"
#include <stdio.h>
#include "random.hpp"
#include "stock.hpp"


double monte_carol( const option & theOption,        // type of option, call or put
                   
                    const stock& stock,              // model of stock price model, ex, BGM of Jump diffusion..etc
                   
                    double S_0,                      // stock price now
                   
                    double vol,                       //sigma
                    double r,                         //interest rate
                    unsigned long number_of_paths     //compute the expectation of future stock price,
                                                      //generate lot of random numbers, and take average
);





#endif /* MonteCarol_hpp */
