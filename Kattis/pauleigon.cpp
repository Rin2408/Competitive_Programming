#include <iostream>
#include <cmath>

int main(){
    int n,x,y; std::cin >> n >> x >> y;
    int cnt=(1ll*x+y)/n;
    if(cnt%2) std:: cout << "opponent";
    else std::cout << "paul";
}