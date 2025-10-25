//NOT DONE
#include <bits/stdc++.h>
using namespace std;
#define NAMEFILE "roboherd"
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
#define MAXN 100005
#define fi first
#define se second
#define All(V) V.begin(), V.end()
typedef long long LL;
typedef vector<int> vi;
typedef vector<LL> vl;
typedef pair<long long,int> pli;
typedef tuple<long long, int, int> tlii;
const LL MAX = 1e15;
const LL MIN = -1e15;
const int NMAX = 2e5 + 5;
string S;
int N, K,M[MAXN],CNTA=0; vector<pli> V;
LL CNT[MAXN], A[MAXN][15],B[MAXN][15],Pre[MAXN][15];
vector< pair<int,int> > VLIST[NMAX];
//bitset<NMAX> BLIST[NMAX];
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
    cin >> N  >> K;
    FOR(i,1,N){
        cin >> M[i];
        FOR(j,1,M[i]) cin >> A[i][j];
        sort(A[i]+1,A[i]+1+M[i]);
    }
}
void process() {
    LL TMUL= 1;
    LL TSUM = 0;
    LL ANS = 0;
    int INDEX;
    FOR(i,1,N){
        B[i][1]=A[i][1];
        ++CNT[i];
        TSUM += B[i][1];
        VLIST[1].pb({i,1});
        FOR(j,2,M[i]){
            Pre[i][j] = A[i][j] - A[i][j-1] + Pre[i][j-1];
            V.pb({Pre[i][j],i});
        }
    }
    ++CNTA;
    sort(All(V),[&](const pli &A, const pli &B){ return (A.fi < B.fi || (A.fi == B.fi && A.se < B.se));});
    for(auto x : V){
        LL _V; int I;
        tie(_V,I) = x;
        B[I][++CNT[I]] = _V + B[I][1];
        debug(_V);
        TMUL = TMUL/(CNT[I]-1)*CNT[I];
        if(TMUL>=K) break;
    }
    V.clear();
    /* FOR(i,1,N){
        FOR(j,1,CNT[i]){
            cout << B[i][j] << ' ';
        }
        cout << endl;
    } */
    priority_queue<pli,vector<pli>,greater<>>PQ;
    PQ.push({TSUM,1});
    while(K--){
        tie(TSUM,INDEX) = PQ.top();
        ANS += TSUM;
        PQ.pop();
       // cout << TSUM << endl;
        for(auto x : VLIST[INDEX]){
            int I,J; tie(I,J) = x;
            if(!B[I][J+1]) continue;
            VLIST[++CNTA] = VLIST[INDEX];
            VLIST[CNTA][I-1] = {I,J+1};
            PQ.push({TSUM+B[I][J+1]-B[I][J],CNTA});
        }
    }
    cout << ANS;
}
int main() {
    FastIO;
    file(NAMEFILE)
    int T = 1;
 //   cin >> T;
    while (T--) {
        init();
        process();
    }
    return 0;
}