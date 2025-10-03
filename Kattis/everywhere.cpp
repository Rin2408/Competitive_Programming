#include <iostream>

std::string S[105];

int main(){
    int T; std::cin >> T;
    while(T--){
        int N, I=0; 
        std::cin >> N;
        for(int i=1; i <= N; ++i){
            std::string TMPS; 
            std::cin >> TMPS;
            bool Visited = 1;
            for(int j=1; j<=I; ++j){
                if(S[j] == TMPS) Visited = 0;
            }
            if(Visited) S[++I] = TMPS;
        }
        std::cout << I << std::endl;
    }
}