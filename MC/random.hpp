//
//  random.hpp
//  Monte_Carol_Fincace
//
//  Created by Chih Chi Chou on 12/31/16.
//  Copyright © 2016 C Chou. All rights reserved.
//

#ifndef random_hpp
#define random_hpp

#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>


/********************* Random variables ********************/

//return a standard normal random variable.
double box_muller();

//return a Poisson random variable.
int Poisson(double lambda) ;


//return a Wiener process
std::vector<double> wiener(double T, int NumOfPeriod);

//return a process of geoemetirc Brownian motion
std::vector<double> GBM_rv(double T, int NumOfperiod,
                        double mu,                   //drift
                        double s_0,                  //initial value of stock proce
                        double sigma
                        );



/********************* Stcok Price   ********************/

//Stock price of Diffusion Process
double JumpDiffStock(double s_0,            //initial stock price
                     double mu,
                     double sigma,
                     double T,
                     int num_terms,
                     double lambda,         //assumeing number of jumps follows Poisson(lambda), note that in each                            subinterval, we need to take lambda/num_terms
                     double a,              //Assuming jump Y_j is log normal (a,b^2)
                     double b);





#endif /* random_hpp */
