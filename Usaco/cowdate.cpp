/* SUB 1: N<=4000
the process of calculating the percentage of inviting an interval
from j->i (j<=i) is 
*/
#include <bits/stdc++.h>
using namespace std;
#define NAMEFILE "cowdate"
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
int N;
long double A[MAXN];
long double MAXV=0,MAXS=0,MAXL=0;
long double L=0,S=1,_S[MAXN],_L[MAXN];
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
    FOR(i,1,N){
        cin >> A[i];
        A[i] /= 1e6;
      //  cout << A[i] << endl;
    }
}
void process() {
    long double ANS = 0;
    FOR(i,1,N){
        S *= (1 - A[i]);
        L += A[i] / (1 - A[i]);
        Max(ANS,S*L);
    //    cout <<"haha 1: "<<ANS << endl;
        if(MAXS) Max(ANS,(S/MAXS)*(L-MAXL));
 //       cout <<"haha 2: "<<ANS << endl;
        if( Max(MAXV,((2.0-L)/S)) ){
            MAXL = L;
            MAXS = S;
            cout<<i<<endl;
        }
    }
    cout << int(floor(ANS*1e6))<<endl;
}
void FINDANS(){
    long double ANS = 0;
    _S[0]=1;
    int ST=1;
    FOR(i,1,N){
        long double _ANS=0;
        _S[i] = (1 - A[i])*_S[i-1];
        _L[i] = A[i] / (1 - A[i]) + _L[i-1];
        Max(ANS,_S[i]*_L[i]);
        FOR(j,ST,i-1){
           // cout<<j<<' '<<i<<' '<<ANS<<endl;
           // cout<<(_S[i]/_S[j])*(_L[i]-_L[j])<<endl;
            if(Max(_ANS,(_S[i]/_S[j])*(_L[i]-_L[j]))){
               // cout<<j<<' '<<i<<' '<<ANS<<endl;
               ST=j;
            }
            else break;
        }
       // debug(ST);
        Max(ANS,_ANS);
        //cout<<(2.0-_L[i])/_S[i]<<endl;
    }
    cout << int(floor(ANS*1e6));
}
int main() {
    FastIO;
    file(NAMEFILE);
    int T = 1;
    while (T--) {
        init();
       // process();
        FINDANS();
    }
    return 0;
}