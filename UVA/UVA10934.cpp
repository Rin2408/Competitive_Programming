#include <bits/stdc++.h>
using namespace std;
#define NAMEFILE "UVA10934"
#define file(NAMEFILE) freopen(NAMEFILE ".in", "r", stdin); freopen(NAMEFILE ".out", "w", stdout);
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FOD(i, a, b) for (int i = a; i >= b; --i)
#define REP(i, a, b) for (int i = a; i < b; ++i)
#define FastIO ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << ": " << x << endl;
#define LOG 19
#define MOD 1000000007
#define BIT(x, i) ((x >> i) & 1)
#define eb emplace_back
#define pb push_back
#define sz(v) ((int)v.size())
#define MAXN 1000005
#define fi first
#define se second
#define All(V) V.begin(), V.end()
typedef long long LL;
typedef vector<int> vi;
typedef vector<LL> vl;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
typedef pair<LL,int> PLL;
const LL MAX = 1e15;
const LL MIN = -1e15;
const int NMAX = 2e5 + 5;
LL N; int K;
LL DP[105];
template<typename T, typename R>
bool Max(T &A, const R&B){
   if(A<=B){
       A=B;
       return 1;
   }
   return 0;
}
template<typename T, typename R>
bool Min(T &A, const R&B){
   if(A>=B){
       A=B;
       return 1;
   }
   return 0;
}
void init() {
    cin >> K >> N;
    K--;
}
void Cal(LL L, LL R, int CNT, int CNTB){
    if(CNT>63){
        Min(DP[64],R);
        return;
    }
    if(L>R) return;
    if(CNTB == 0 || L==R){
            if(DP[min(1ll*64,R-L+CNT)]>R){
                cout << min(1ll*64,R-L+CNT) << ' ' << R << ' ' << L << endl;
                Min(DP[min(1ll*64,R-L+CNT)],R);
            }
        return;
    }
   // debug(CNT);
    return Cal(L,M-1,CNT+1,CNTB-1)+Cal(M+1,R,CNT+1,CNTB);
}
void process() {
    FOR(i,0,64) DP[i]=9223372036854775807;
    Cal(1,N,0,K);
}
int main() {
    FastIO;
    file(NAMEFILE)
    int T = 1;
   // cin >> T;
    while (T--) {
        init();
        process();
    }
    return 0;
}