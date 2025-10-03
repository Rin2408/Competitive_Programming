#include <iostream>
#include <cmath>

std::string S[105];
int CMP(const std::string &A, const std::string &B){
    for(int i=0; i< std::min(A.size(),B.size()); ++i){
        if(A[i]<B[i]) return 1;
        else if(A[i] > B[i] )return 2;
    }
    if (A.size() < B.size()) return 1;  
    return 2;
}
int main(){
    int N; std::cin >> N;
    for(int i=1; i<=N; ++i) std::cin >> S[i];
    int STATUS=0;
    for(int i=1; i<=N-1; ++i){
        int TMP=CMP(S[i],S[i+1]);
        if(i==1) STATUS=TMP;
        if(TMP != STATUS) STATUS=0;
    }
    if(STATUS == 1) std::cout << "INCREASING";
    else if(STATUS == 2)std::cout << "DECREASING";
    else std::cout << "NEITHER";
}