#include <iostream>
#include <cmath>

int x[10];
int main(){
    int sum=0;
    for(int i=0;i<9;++i){
        std::cin >> x[i];
        sum+=x[i];
    }
    for(int i=0;i<9;++i){
        for(int j=i+1;j<9;++j){
            if(sum-x[i]-x[j]==100){
                for(int k=0;k<9;++k){
                    if(k==i || k==j) continue;
                    std::cout<<x[k]<<std::endl;
                }
                return 0;
            }
        }
    }
}