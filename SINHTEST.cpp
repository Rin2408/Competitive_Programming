#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
mt19937_64 rd(time(0));
long long Rd(const long long &L, const long long &R){
    return L+rd()%(R-L+1);
}
void GEN(void){
    ofstream cout("D:\\Competitive_Programming\\Codetour\\DOT1\\NAM2025\\TrongTam.inp");
    int N=Rd(2,20);
    cout<<N<<' '<<Rd(2,N)<<endl;
    while(N--){
        cout<<Rd(1,100)<<' '<<Rd(1,100);
        cout<<endl;
    }
    cout.close();
}
int main(void){
    int NumTest=10;
    for(int i=1;i<=NumTest;++i){
        system("D:\\Competitive_Programming\\Codetour\\DOT1\\NAM2025\\TrongTam.exe");
        system("D:\\Competitive_Programming\\Codetour\\DOT1\\NAM2025\\TrongTam_trau.exe");
        GEN();
        cout<<"#Test: "<<i<<" is ";
        if(system("fc D:\\Competitive_Programming\\Codetour\\DOT1\\NAM2025\\TrongTam.out D:\\Competitive_Programming\\Codetour\\DOT1\\NAM2025\\TrongTam.ans")){
            cout<<"incorrect";
            break;
        }
        cout<<"correct"<<endl;        
    }
}