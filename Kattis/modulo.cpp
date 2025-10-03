#include <iostream>
#include <cmath>
using namespace std;
int cnt[50];
int ans=0;
int main(){
    int x;
    while(cin>>x) ++cnt[x%42];
    for(int i=0;i<42;++i) ans+=(cnt[i]>0);
    cout<<ans;
}