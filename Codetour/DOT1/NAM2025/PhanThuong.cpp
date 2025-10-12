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
#define MAXN 100005
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
int N;
pii P[NMAX];
vi V;
template<typename T>
bool Max(T &A, const T&B){
    if(A<=B){
        A=B;
        return 1;
    }
    return 0;
}
struct FWT{
    LL Val[NMAX],MAXV=0;
    int CNT[NMAX],MAXCNT=0;
    FWT(){
        memset(Val,0,sizeof(Val));
        memset(CNT,0,sizeof(CNT));
    }
    pair<LL,int> Get(int POS){
        LL MaxV=0;
        int TmpCNT=0;
        for(;POS;POS-=(POS&-POS)){
            if(MaxV==Val[POS]) Max(CNT[POS],TmpCNT);
            else if(Max(MaxV,Val[POS])) TmpCNT=CNT[POS];
        }
        return {MaxV,TmpCNT};
    }
    void Set(int POS, LL TmpVal, int TmpCNT){
        for(;POS<sz(V)+1;POS+=(POS&-POS)){
            if(TmpVal==Val[POS]) Max(CNT[POS],TmpCNT);
            else if(Max(Val[POS],TmpVal)) CNT[POS]=TmpCNT;
        }
    }
}DP;
void init(void){
    cin >> N;
    FOR(i,1,N){
        cin >> P[i].fi;
        V.eb(P[i].fi);
    }
    FOR(i,1,N) cin >> P[i].se;
    sort(All(V));
    V.erase(unique(All(V)),V.end());
}
void process(void){
    FOR(i,1,N){
        int TmpIndex = lower_bound(All(V),P[i].fi) - V.begin() +1;
        pair<LL,int> TMP = DP.Get(TmpIndex-1);
     //   cout<<DP.Val[TmpIndex]<<' '<<TMP.fi<<endl;
        if(TMP.fi+P[i].se>=DP.MAXV){
            if(TMP.fi+P[i].se==DP.MAXV) Max(DP.MAXCNT,TMP.se+1);
            else if(Max(DP.MAXV,TMP.fi+P[i].se)) DP.MAXCNT=TMP.se+1;
        }
        DP.Set(TmpIndex,TMP.fi+P[i].se,TMP.se+1);
       // cout<<TMP.se+1<<endl;
    }
    cout << DP.MAXV << ' ' << DP.MAXCNT;
}
int main(void){
    FastIO
    int T=1;
    while(T--){
        init();
        process();
    }
    return 0;
}