#include <bits/stdc++.h>
using namespace std;
#define NAMEFILE "wormsort"
#define file(NAMEFILE) freopen(NAMEFILE".in","r",stdin);freopen(NAMEFILE".out","w",stdout);
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
#define SIZE(v) (int)v.size()
#define MAXN 100005
typedef long long LL;
typedef vector<int> vi;
typedef vector<LL> vl;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
const LL MAX=1e15;
const LL MIN=-1e15;
int N,M;
int A[MAXN],x_current=0,ans;
bool is_correct=1,Visit[MAXN],C2[MAXN];
int C[MAXN];
vector<tiii>Worm_Holes;
vi V[MAXN],adj[MAXN];
void init(void){
    cin>>N>>M;
    FOR(i,1,N){
        cin>>A[i];
        if(i!=A[i]) is_correct=0;
    }
    FOR(i,1,M){
        int u,v,w; cin>>u>>v>>w;
        Worm_Holes.pb({u,v,w});
    }
   // debug(SIZE(Worm_Holes));
}
void dfs(int u, int par){
    Visit[u]=1;
    C[u]=par;
    REP(i,0,SIZE(adj[u])){
        int v=adj[u][i];
        if(!Visit[v]) dfs(v,par);
    }
}
void add_adj(const int &x){
   // debug(x);
    if(x_current<x){
       // debug(x_current); debug(x);
        for(;x_current<=x;x_current++){
            int u,v,w;
            tie(u,v,w)=Worm_Holes[x_current];
            adj[u].pb(v);
            adj[v].pb(u);
        // debug(u); debug(v);
        }
        x_current--;
    }
    else{
        //debug(x_current); debug(x);
        for(;x_current>x;x_current--){
            int u,v,w;
            tie(u,v,w)=Worm_Holes[x_current];
        //   debug(u); debug(v);
            adj[u].pop_back();
            adj[v].pop_back();
        }
    }
    
}
bool check(const int &x){
    add_adj(x);
    bool ANS=1;
    FOR(i,1,N){
        if(SIZE(V[i]) && !Visit[i]){
            dfs(i,i);
            //cout<<SIZE(V[i])<<' '<<i<<endl;
        }
        REP(v,0,SIZE(V[i])){
            // debug(Visit[v]);
            ANS&=(C[V[i][v]]==C[i]);
           // cout<<C[i]<<' '<<i<<' '<<V[i][v]<<' '<<x<<endl;
            //cout<<C2[V[i][v]]<<' '<<V[i][v]<<endl;
            // debug(ANS);
            //debug(v);
            //debug(i);
            // debug(SIZE(V[i]));
        }
    }
    FOR(i,1,N) Visit[i]=0,C[i]=0;
    //debug(ANS);
    //debug(x_current);
   // debug(x);
    return ANS;
}
void BS(void){
    int L=0,R=M-1;
    //debug(R);
    while(L<=R){
        int m=(L+R)>>1;
        if(check(m)){
            ans=get<2>(Worm_Holes[m]);
           // debug(ans);
            R=m-1;
        }
        else L=m+1;
      //  debug(get<2>(Worm_Holes[m]));
    }
}
void precal(void){
    FOR(i,1,N){
        if(C[i]) continue;
        int u=A[i];
        V[i].pb(i);
        C[i]=i;
        while(i!=u){
            V[i].pb(u);
            C[u]=i;
            u=A[u];
        }
        //debug(SIZE(V[i]));
        //debug(i);
    }
    sort(Worm_Holes.begin(),Worm_Holes.end(),[&](const tiii &a, const tiii &b) { return (get<2>(a)>get<2>(b));});
    /*REP(i,0,206){
        int u,v,w;
        tie(u,v,w)=Worm_Holes[i];
        cout<<u<<' '<<v<<' '<<w<<endl;
    }*/
   //debug(SIZE(Worm_Holes));
}
void DSU(void);
void process(void){
    if(is_correct) cout<<-1;
    else{
        precal();
        BS();
       // DSU();
       cout<<ans;
    }   
}
int main(void){
    FastIO
    file(NAMEFILE)
    int T=1; //cin>>T;
    while(T--){
        init();
        process();
    }
}