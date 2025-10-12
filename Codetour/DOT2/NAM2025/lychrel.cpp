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
int N,M;
template<typename T>
bool Max(T &A, const T&B){
    if(A<=B){
        A=B;
        return 1;
    }
    return 0;
}
bool CheckLychrel(const string &A){
    REP(i,0,sz(A)/2) if(A[i]!=A[sz(A)-i-1]) return false;
    return true;
}
string Cal(const string &A){
    string TMP="";
    int Memory=0;
    REP(i,0,sz(A)){
        int a=(A[i]-'0');
        int b=(A[sz(A)-i-1]-'0');
        int c=a+b+Memory;
        Memory=c/10;
      //  debug(c);
        c%=10;
       // TMP=(c+'0')+TMP;
       TMP+=(c+'0');
    }
    if(Memory){
        //TMP=(c+'0')+TMP;
        TMP+=(Memory+'0');
    }
    reverse(TMP.begin(),TMP.end());
    return TMP;
}
void init(void){
    cin>>S>>N>>M;
}
void process(void){
    int cnt=0;
    while(cnt<N && sz(S)<=M){
        if(CheckLychrel(S)){
            cout<<"NO"<<endl<<cnt<<endl<<S;
            return;
        }
        S=Cal(S);
        ++cnt;
    }
    cout<<"YES"<<endl<<cnt<<endl<<S;
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