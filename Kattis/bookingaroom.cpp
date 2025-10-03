#include <iostream>
bool Booked[105];
int main(){
    int R, N; std::cin >> R >> N;
    if(N == R) std::cout << "too late";
    else{
        for(int i=1 ; i <= N ; ++i){
            int X; std::cin >> X;
            Booked[X]=1;
        }
        for(int i=1 ; i <= R ; ++i){
            if(!Booked[i]){
                std::cout << i;
                break;
            }
        }
    }
}