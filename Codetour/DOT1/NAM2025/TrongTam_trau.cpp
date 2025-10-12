#include <bits/stdc++.h>
using namespace std;
#define NAMEFILE "TrongTam"
#define file(NAMEFILE) freopen(NAMEFILE".inp","r",stdin);freopen(NAMEFILE".ans","w",stdout);
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
typedef long long LL;
typedef vector<int> vi;
typedef vector<LL> vl;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
const LL MAX=1e15;
const LL MIN=-1e15;
const int NMAX=2e5+5;
int N, K, A[NMAX], B[NMAX];
void init(void){
    cin >> N >> K;
    FOR(i,1,N) cin >> A[i] >> B[i];
}
void process(void){
    long long ans=0;
    REP(i,0,1<<N){
        long long X=0,Y=0;
        int cnt=0;
        REP(j,0,20){
            if(BIT(i,j)){
                cnt++;
                X+=A[j+1];
                Y+=B[j+1];
            }
        }
        if(cnt==K && X%K==0 && Y%K==0) ans++;
        ans%=MOD;
    }
    cout<< ans;
}
int main(void){
    FastIO
    file(NAMEFILE);
    int T=1;
    while(T--){
        init();
        process();
    }
    return 0;
}