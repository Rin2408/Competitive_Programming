#include <bits/stdc++.h>

int main(void){
    double R, C; std::cin >> R >> C;
    std::cout << std::fixed << std::setprecision(6) << ((R-C)*(R-C)/(R*R))*100.0;
}