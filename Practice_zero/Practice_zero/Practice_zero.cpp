#include <iostream>
#include "Practice0.h" 

int main()
{
    TVector v1, v2;
    int n;
    std::cin >> v1 >> v2;
    TVector res1 = v1 + v2; 
    TVector res2 = v1 - v2;
    TVector res3 = v1 * v2;
    
    std::cout << v1;
    std::cout << v2;
    std::cout << res1;
    std::cout << res2;
    std::cout << res3;
    
    return 0;
}