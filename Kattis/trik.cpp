#include <bits/stdc++.h>

int main(void){
    std::string S; std::cin >> S;
    int A=1, B=0, C=0;
    for(int i=0;i<S.size();++i){
        if(S[i]=='A') std::swap(A,B);
        else if(S[i]=='B') std::swap(B,C);
        else std::swap(A,C);
    }
    if(A) std::cout << 1;
    else if(B) std::cout << 2;
    else std::cout << 3;
}