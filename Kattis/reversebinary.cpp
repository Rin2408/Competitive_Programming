#include <iostream>
#include <cmath>
using namespace std;
int BIT[50];
int main(){
    int index=0;
    long long x; cin>>x;
    long long ans=0;
    long long tmp=1;
    while(x){
        BIT[index]=x%2;
        x/=2;
        tmp*=2;
        ++index;
    }
    tmp/=2;
    for(int i=0;i<index;++i){
        ans+=tmp*BIT[i];
        tmp/=2;
    }
    cout<<ans;
}