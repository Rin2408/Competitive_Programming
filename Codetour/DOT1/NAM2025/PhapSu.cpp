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
#define MAXN 200005
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
int N,M,OP1[MAXN];
LL OP2[MAXN],SubOP2[MAXN];
void init(void){
    cin >> N >> M;
    FOR(i,1,M){
        int K,L,R;
        cin>>K>>L>>R;
        if(K==0) OP1[L]+=1,OP1[R+1]+=-1;
        else if(K==1) OP1[L]+=-1,OP1[R+1]+=1;
        else if(K==2){
            SubOP2[L]+=1,SubOP2[R+1]+=-1;
            OP2[L]+=1,OP2[R+1]+=-1*(R+2-L);
        }
        else{
            SubOP2[L]+=-1,SubOP2[R+1]+=1;
            OP2[L]+=-1,OP2[R+1]+=(R+2-L);
        }
        
    }
}
void process(void){
    //cout<<endl;
    FOR(i,1,N){
        OP1[i]+=OP1[i-1];
        SubOP2[i]+=SubOP2[i-1];
        OP2[i]+=(OP2[i-1]+SubOP2[i-1]);
        //cout<<OP1[i]<<' '<<OP2[i]<<' '<<SubOP2[i]<<endl;
        cout<<OP1[i]+OP2[i]<<' ';
    }
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