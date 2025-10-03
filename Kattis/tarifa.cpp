#include <iostream>

int main(void){
     int X, N; std::cin >> X >> N;
     int ans=0;
     for(int i=1;i<=N;++i){
        int A; std::cin >> A;
        ans+=(X-A);
     }
     std::cout << ans + X;
}