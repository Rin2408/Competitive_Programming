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
int PrefS[30][NMAX],INDEX,v[30];
template<typename T>
bool Max(T &A, const T&B){
    if(A<=B){
        A=B;
        return 1;
    }
    return 0;
}
void init(void){
    cin>>S;
}
void process(void){
    FOR(i,1,sz(S)){
        for(int j=97;j<=122;++j){
            PrefS[j-97][i]=PrefS[j-97][i-1]+(S[i-1]==char(j-97+'a'));
           // debug(PrefS[j-97][i]);
        }
    }
    FOD(i,sz(S),1){
      //  cout<<"ans: "<<i<<endl;
        FOR(j,i,sz(S)){
          //  cout<<"from to: "<<j<<' '<<j-i<<endl;
            bool flag=1;
            for(int k=97;k<=122;++k){
                if(PrefS[k-97][j]-PrefS[k-97][j-i]){
                    v[INDEX]=PrefS[k-97][j]-PrefS[k-97][j-i];
                    ++INDEX;
                }
            }
           // debug(sz(v));
            for(int k=0;k<INDEX-1;++k){
                if(v[k]!=v[k+1]){
                    flag=0;
                    break;
                }
            }
            if(flag){
                cout<<i;
                return;
            }
            INDEX=0;
        }
    }
    cout<<0;
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