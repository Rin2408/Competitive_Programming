#include <iostream>
#include <cmath>
int sum[2];
int main(){
    for(int i=0;i<2;++i){
        for(int j=0;j<4;++j){
            int x;
            std::cin >> x;
            sum[i]+=x;
        }
    }
    if(sum[0]>sum[1]) std::cout << "Gunnar";
    else if(sum[0] < sum[1]) std::cout << "Emma";
    else std::cout << "Tie";
}