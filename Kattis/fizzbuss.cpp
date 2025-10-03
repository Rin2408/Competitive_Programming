#include <iostream>

int main(void){
    int X, Y ,N; std::cin >> X >> Y >>N;
    for(int i=1;i<=N;++i){
        if(i%X==0 && i%Y==0) std::cout << "FizzBuzz";
        else if(i%X==0) std::cout << "Fizz";
        else if(i%Y==0) std::cout <<"Buzz";
        else std::cout << i;
        std::cout << std::endl;
    }
}