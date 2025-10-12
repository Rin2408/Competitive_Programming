#include <bits/stdc++.h>
using namespace std;
#define NAMEFILE "TrongTam"
#define file(NAMEFILE) freopen(NAMEFILE".inp","r",stdin);freopen(NAMEFILE".out","w",stdout);
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
#define sz(v) (int)v.size()
#define MAXN 1000005
#define fi first
#define se second
#define All(V) V.begin(),V.end()
typedef long long LL;
typedef vector<int> vi;
typedef vector<LL> vl;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
const LL MAX=1e15;
const LL MIN=-1e15;
const int NMAX=2e5+5;
string S;
template<typename T>
bool Max(T &A, const T&B){
    if(A<=B){
        A=B;
        return 1;
    }
    return 0;
}
void init(void){
    cin>>S;
}
void process(void){
    bool flag1=(S[0]=='A' || S[0]=='B'),flag2=(S[0]=='A');
    int cntA=(S[0]=='A');
    FOR(i,2,sz(S)){
        if(S[i-1]=='A') cntA++;
        if(S[i-1]==S[i-2] && S[i-1]=='A') flag1=0,flag2=0;
        if(S[i-1]!='A' && S[i-1]!='B') flag1=0,flag2=0;
        //debug(flag1);
    }
    if(flag1 && cntA) cout<<"YES ";
    else cout<<"NO ";
    if(flag2) cout<<"YES\n";
    else cout<<"NO\n";
}
int main(void){
    FastIO
    int T=1; cin>>T;
    while(T--){
        init();
        process();
    }
    return 0;
}