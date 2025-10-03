#include <iostream>

int main(void){
    int N; std::cin >> N;
    int ans=0;
    for(int i=1;i<=N;++i){
        int x; std::cin >> x;
        if(x<0) ans++;
    }
    std::cout << ans;
}