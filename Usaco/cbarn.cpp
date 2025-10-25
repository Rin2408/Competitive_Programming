#include <bits/stdc++.h>
using namespace std;
#define NAMEFILE "cbarn"
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
const LL MAX = 1e15;
const LL MIN = -1e15;
const int NMAX = 2e5 + 5;
string S;
int N, M=INT_MAX;
int A[NMAX];
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
    cin >> N;
    FOR(i, 1, N) {
        cin >> A[i];
    }
    FOR(i,1,N){
        A[i+N]=A[i];
    }
}
void process() {
    FOR(i,1,N){
        int TANS = 0;
        FOR(j,i,i+N-1){
            TANS += A[j]*(j-i);
        }
        Min(M,TANS);
    }
    cout << M << endl;
}
int main() {
    FastIO;
    file(NAMEFILE);
    int T = 1;
  //  cin >> T;
    while (T--) {
        init();
        process();
    }
    return 0;
}