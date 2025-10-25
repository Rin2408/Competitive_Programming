//TLE
#include <bits/stdc++.h>
using namespace std;
#define NAMEFILE ""
#define file(NAMEFILE) freopen(NAMEFILE ".inp", "r", stdin); freopen(NAMEFILE ".out", "w", stdout);
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
#define MAXN 105
#define fi first
#define se second
#define All(V) V.begin(), V.end()
typedef long long LL;
typedef vector<int> vi;
typedef vector<LL> vl;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
const LL MAX = 1e15;
const LL MIN = -1e15;
const int NMAX = 2e5 + 5;
string S;
int N,C[5],Q,D[5],V;
LL DP[5][NMAX];
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
    FOR(j,1,4) cin >> C[j];
    cin >> Q;
}
void process() {
    FOR(i,1,4) cin >> D[i];
    cin >> V;
    FOR(i,1,4){
        DP[i-1][0]=1;
        FOR(j,1,D[i]){
            FOR(k,j*C[i],V){
                if(!DP[i][k]) DP[i][k]+=DP[i-1][k];
                DP[i][k]+=DP[i-1][k-j*C[i]];
            }
        }
    }
    cout << DP[4][V] << endl;
   // debug(DP[2][900]);
    memset(DP,0,sizeof(DP));
}
int main() {
    FastIO;
    int T = 1;
    cin >> T;
    while (T--) {
        init();
        while(Q--){
            process();
        }
    }
    return 0;
}