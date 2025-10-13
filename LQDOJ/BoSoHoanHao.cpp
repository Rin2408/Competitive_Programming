//NOT DONE
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
#define MOD 1234567891
#define BIT(x, i) ((x >> i) & 1)
#define eb emplace_back
#define pb push_back
#define sz(v) ((int)v.size())
#define MAXN 2000005
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
int N,V[15][65],CNT=0;
int LISTPRIMES[15]={0, 2, 3, 5, 7, 13, 17, 19, 31, 61};
long long PRIMES[15],DP[61];
long long InverMOD[MAXN],_CNT1;
__int128_t A[MAXN];
vector<int>VF2;
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
void CAL1(){
    long long TMP=1;
    FOR(i,1,CNT1){
        TMP*=i;
        if(TMP>=MOD) TMP%=MOD;
    }
    long long _MOD=MOD-2,_TMP=1;
    for(;_MOD;TMP=(TMP*TMP)%MOD,_MOD>>=1) if(_MOD&1) _TMP=(_TMP*TMP)%MOD;
    (_CNT1+=_TMP)%=MOD;
    FOD(i,MAXN-1,1){
        
        
    }
}
void PreCal(void){
    long long TMP=1;
    FOR(i,1,9){
        int CNT=LISTPRIMES[i]-LISTPRIMES[i-1];
        while(CNT--) TMP*=2;
        PRIMES[i]=TMP-1;
        //cout<<PRIMES[i]<<endl;
    }
}
void print(__int128_t A){
    char DIGITS[105];
    short index=0;
    if(A<0) DIGITS[index++]='-';
    else if(A==0){
        cout<<0;
        return;
    }
    else{
        while(A){
            short TMP=A%10;
            A/=10;
            DIGITS[index++]=(TMP+'0');
        }
        FOD(i,index-1,0) cout<<DIGITS[i];
    }
}
__int128_t input(const string &TMP){
    __int128_t TMPN=0;
    REP(i,0,sz(TMP)){
        TMPN*=10;
        TMPN+=(TMP[i]-'0');
    }
    return TMPN;
}
void init() {
    cin>>N;
    string TMP;
    FOR(i,1,N){
        cin>>TMP;
        A[i]=input(TMP);
    }
}
void process() {
    PreCal();
    long long ANS=0;
    FOR(i,1,N){
        if(A[i]==1){
            ++CNT1;
            continue;
        }
        FOR(j,1,9){
          //  cout<<i<<' '<<j<<endl;
            if(A[i]==PRIMES[j]){
              //  print(A[i]); cout<<endl;
                ++V[j][0];
                break;
            }
            else if(A[i]%PRIMES[j]==0){
                int TMP=0;
                while(A[i]%2==0){
                    ++TMP;
                    A[i]/=2;
                }
                if(A[i]==PRIMES[j]) ++V[j][TMP];
                break;
            }
        }
        if(A[i]%2==0){
            int TMP=0;
            while(A[i]%2==0){
                ++TMP;
                A[i]/=2;
            }
            if(TMP<61) VF2.eb(TMP);
        }
    }
    DP[0]=1;
    CAL1();
    REP(i,0,sz(VF2)){
        FOD(j,60,VF2[i]){
            DP[j]+=DP[j-VF2[i]];
            if(DP[j]>=MOD) DP[j]-=MOD;
        }
    }
    FOR(i,1,9){
        FOR(j,0,60){
            if(!V[i][j]) continue;
            ANS=V[i][j]*DP[j];
            if(ANS>=MOD) ANS%=MOD;
            ANS=ANS*_CNT1;
            if(ANS>=MOD) ANS%=MOD;
        }
    }
    cout<< ANS;
    
}
int main() {
    FastIO;
    int T = 1;
   // cin >> T;
    while (T--) {
        init();
        process();
    }
    return 0;
}