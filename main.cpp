//
//  main.cpp
//  Monte_Carol_Fincace


#include <iostream>
#include <vector>
#include "stock.hpp"
#include "payoff2.hpp"
#include "option.hpp"
#include "MonteCarol.hpp"


using namespace std;

int main() {
    
    payOff_call c(105);          //plug in strike price
    
    vanilla_option   v(c, 5);
    
    vanilla_option v2(c, 10);
    
    
    cout<< v2.get_expire();
    
    
    //GBM_one_spot  s(0.2, 0.1, 100);
    
    //cout<< monte_carol(v, s, 100, 0.1, 0.2, 100000000)<<endl;
    
    
    return 0;
}
