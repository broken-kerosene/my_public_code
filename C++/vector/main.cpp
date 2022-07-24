#include "vector.h"
#include<iostream>
int main()
{
    Vector a;
    std::cout << a.cp << ' ' << a.num << std::endl;
    a.push_back(10);
    std::cout << a.cp << ' ' << a.num << std::endl;
    a.push_back(10);
    std::cout << a.cp << ' ' << a.num << std::endl;
    Vector b = a;
    std::cout << b.cp << ' ' << b.num << std::endl;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    for(unsigned int i = 0; i < b.num; i++){
        std::cout << b[i] << std::endl;
    }
    return 0;
}
