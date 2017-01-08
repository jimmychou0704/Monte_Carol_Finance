//
//  random.cpp
//  Monte_Carol_Fincace
//


#include "random.hpp"

double box_muller(){
    double pi = 3.14159265;
    //srand( (int)time(0));
    double x = (double)rand()/RAND_MAX;
    
    double y = (double) rand()/RAND_MAX;
    
    return sqrt((-2)*log(x))*cos(2*pi*y);
    //return x;
    
    
    
    
    
}

//return a Poisson random variable.
int Poisson(double lambda) {
    int k = 0;
    double p = exp(-1 * lambda);
    double F = p;
    double u = (double) rand()/RAND_MAX;
    
    while (u> F){
        k += 1;
        p *= lambda/ k;
        F += p;
    }
    return k;
    
    
}





std::vector<double> wiener(double T, int NumOfPeriod){
    std::vector<double> W;
    
    double dT = T/NumOfPeriod;
    double w_ = 0;
    W.push_back(w_);
    for (int i = 0; i< NumOfPeriod-1; i++){
        double z = box_muller();
        w_ = w_ + sqrt(dT)* z;
        W.push_back(w_);
    }
    
    
    return W;
    
}


std::vector<double> GBM_rv(double T, int NumOfPeriod,
                        double mu,                   //drift
                        double s_0,                  //initial value of stock proce
                        double sigma
                        ){
    std::vector<double> S;
    double s_ = s_0;
    S.push_back(s_);
    double dT = T/NumOfPeriod;
    for (int i = 0; i< NumOfPeriod-1; i++ ){
        double z = box_muller();
        s_ = s_ * exp((mu - 0.5* sigma*sigma)* dT + sigma* sqrt(dT)*z);
        S.push_back(s_);
        
        
        
    }
    
    return S;
    
    
    
    
    
}


double JumpDiffStock(double s_0,            //initial stock price
                     double mu,
                     double sigma,
                     double T,
                     int num_terms,
                     double lambda,         //assumeing number of jumps follows Poisson(lambda), note that in each                            subinterval, we need to take lambda/num_terms
                     double a,              //Assuming jump Y_j is log normal (a,b^2)
                     double b){
    
    double x = log(s_0);
    double dt = T/num_terms;
    lambda = lambda/num_terms;
    for (int i = 0; i< num_terms; i++){
        double z1 = box_muller();           //for wiener process
        double z2 = box_muller();           //for jumps
        int N =  Poisson(lambda);
        x += (mu - 0.5*pow(sigma, 2))*dt+sigma*sqrt(dt)*z1+ a*N+sqrt(N)*b*z2;
        
    }
    
    return exp(x);
    
    
    
}

