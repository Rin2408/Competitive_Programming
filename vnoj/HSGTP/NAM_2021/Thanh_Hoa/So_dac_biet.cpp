#include <bits/stdc++.h>
using namespace std;
#define sz(A) A.size()
#define All(A) A.begin(),A.end()
const int MAXN=1e6+5;
bool is_prime[MAXN];
vector<long long>V,PRIMES;
long long cal(long long num, long long cnt){
    long long ans=1;
    for(;cnt;num*=num,cnt>>=1) if(cnt&1) ans*=num;
    return ans;
}
void sieve(){
    for(int i=2;1ll*i*i<=1e6;++i){
        if(is_prime[i]) continue;
        for(int j=i*i;j<=1e6;j+=i){
            is_prime[j]=1;
        }
    }
    for(int i=2;i<=1e6;++i) if(!is_prime[i]) V.push_back(i);
	for(int i=3;i<=40;++i){
        if(is_prime[i]) continue;
        for(auto X : V){
            long long _X = cal(X,i-1);
            if(_X>1e12) break;
            PRIMES.push_back(_X);
        }
    }
    sort(All(PRIMES)); 
}
int GetNum(long long POS){
    int ans = 0;
    for(auto X : PRIMES){
        if(X > POS) break;
        ans++;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    long long L,R; cin>>L>>R;
    cout << GetNum(R) - GetNum(L - 1);
    return 0;
}