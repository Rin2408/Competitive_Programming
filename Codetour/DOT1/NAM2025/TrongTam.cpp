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
typedef long long LL;
typedef vector<int> vi;
typedef vector<LL> vl;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
const LL MAX=1e15;
const LL MIN=-1e15;
const int NMAX=2e5+5;
int N, K, A[NMAX], B[NMAX];
long long ANS[15][15][15];
void init(void){
    cin >> N >> K;
    FOR(i,1,N) cin >> A[i] >> B[i];
}
void process(void){
    FOR(i,1,N){
        A[i]%=K;
        B[i]%=K;
       // cout<<A[i]<<' '<<B[i]<<endl;
        if(i>1)
            FOD(j,K,2){
                REP(k,0,K){
                    REP(h,0,K){
                        (ANS[(k+A[i])%K][(h+B[i])%K][j] += ANS[k][h][j-1]);
                        if(ANS[(k+A[i])%K][(h+B[i])%K][j]>=MOD) ANS[(k+A[i])%K][(h+B[i])%K][j]-=MOD;
                    // cout<<i<<' '<<j<<' '<<k<<' '<<h<<' '<<ANS[k%K][h%K][j]<<' '<<ANS[(k-A[i])%K][(h-B[i])%K][j-1]<<' '<<A[i]<<' '<<B[i]<<endl;
                    }
                }
            }
        ANS[A[i]][B[i]][1]++;
    }
    cout << ANS[0][0][K];
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