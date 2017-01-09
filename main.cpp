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
    
    //payOff_bridge p_bridge(c);
    
    vanilla_option   v(c, 5);
    
    vanilla_option v2(c, 10);
    
    v2 = v;
    
    cout<< v2.get_expire()<< endl;
    
       
    
    return 0;
}
