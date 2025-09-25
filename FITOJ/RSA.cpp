#include <bits/stdc++.h>
using namespace std;
#define NAMEFILE ""
#define file(NAMEFILE) freopen(NAMEFILE".in","r",stdin);freopen(NAMEFILE".out","w",stdout);
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FOD(i,a,b) for(int i=a;i>=b;--i)
#define REP(i,a,b) for(int i=a;i<b;++i)
#define FastIO ios::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << ": " << x << endl;
#define LOG 19
#define MOD 1000000007
#define BIT(x,i) ((x>>i)&1)
#define eb emplace_back
#define pb push_back
#define SIZE(v) (int)v.size()
#define MAXN 1000005
typedef long long LL;
typedef vector<int> vi;
typedef vector<LL> vl;
typedef tuple<int,int,int> tiii;
typedef pair<int,int> pii;
const LL MAX=1e15;
const LL MIN=-1e15;
bool prime[MAXN];
vi V; LL N,E,C,TTN,P,Q,D,T;
void Extend_Euclid(LL A, LL B){
    // totient n = a;
    // S = e*s+(totient n)*t=1 => gcd(a,e)=gcd(totien n,e)=1;
    // S % (totient n) => e*s=1 => s=d;
    if(B==0){
       // debug(A);
        D=1;
        T=0;
    }
    else{
        Extend_Euclid(B,A%B);
        LL TMPT=T;
        T=D-(A/B)*T;
        D=TMPT;
    }
}
void init(void){
    cin >> N >> E >> C;
}
void find_totient_n(){
    P=N,Q=1;
    REP(i,1,SIZE(V)){
        if(N%V[i]==0){
            P=V[i];
            Q=N/V[i];
            break;
        }
    }
   // debug(P); debug(Q);
}
LL Cal2(LL A, LL B){
    LL ANS=0;
    for(LL TMP=A;B;B>>=1,TMP=(TMP%N+TMP%N)%N) if(B&1) ANS=(ANS%N+TMP%N)%N;
    return ANS;
}
LL Cal(){
    LL ANS=1;
    for(LL TMP=C%N;T;T>>=1,TMP=Cal2(TMP,TMP)){
        //debug(T);
        if(T&1) ANS=Cal2(ANS,TMP);
    }
    return ANS;
}
void process(void){
    find_totient_n();
    Extend_Euclid((P-1)*(Q-1),E);
  //  debug(D); debug(T);
    while(T<0) T+=(P-1)*(Q-1);
    cout << Cal() <<endl;
}
void precal(){
    for(int i=2;1ll*i*i<MAXN;++i){
        if(!prime[i]){
            for(int j=i*i;j<MAXN;j+=i) prime[j]=1;
        }
    }
    for(int i=2;i<MAXN;++i) if(!prime[i]) V.eb(i);
    //debug(SIZE(V));
}
int main(void){
    FastIO
   // file(NAMEFILE)
    precal();
    int T=1; cin>>T;
    while(T--){
        init();
        process();
    }
}