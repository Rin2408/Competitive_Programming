#include <iostream>
#include <cmath>

int main(void){
    int x, y;
    std::cin >> x >> y;
    if(x*y>0){
        if(std::min(x,y)>0) std::cout << 1;
        else std::cout << 3;
    }
    else{
        if(x>0) std::cout << 4;
        else std::cout << 2;
    }
}