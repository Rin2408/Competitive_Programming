// USE DSU TO FIND THE SPARE EDGE AND MAKE GRAPH
// FIND THE ANS ON THE FIRST GRAPH WHEN WE NOT USE ANOTHER EDGE
// FIND 2 EDGE WHICH IS NEAREST THE U ( U IS THE SMALLEST NODE BETWEEN U AND V (THEM ARE NODES OF SPARE EDGE))
// THEY ARE THE MOST OPTIMIZE EDGE ( PROVE IT BY URSELF)
// TRY EACH CASE WHICH GRAPH IS ADDED SPARE GRAPH AND DELETE ONE OF THEM ( 2 EDGE )
// RETURN THE ANS BETWEEN 3 CASES
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
#define MAXN 100005
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
vi adj[MAXN];
int N,Cnt_BA,D[MAXN];
pii BanAdj[3],Adj[MAXN];
template<typename T>
bool Max(T &A, const T &B){
    if(A<B){
        A=B;
        return 1;
    }
    return 0;
}
struct DSU{
    int CNT[MAXN],Par[MAXN];
    DSU(){};
    int Get(int U){
        if(U==Par[U]) return U;
        return Par[U]=Get(Par[U]);
    }
    bool Set(int U, int V){
        U=Get(U);
        V=Get(V);
        if(U==V) return 0;
        if(CNT[U]<CNT[V]) swap(U,V);
        CNT[U]+=CNT[V];
        Par[V]=U;
        return 1;
    }
}NODE;
struct LCA{
    LCA(){ memset(D,0,sizeof(D)); };
    int Par[LOG][MAXN],CNT=0,D[MAXN];
    tiii FindPar(int U, int V){
        if(this->D[U]<this->D[V]) swap(U,V);
        const int _U=U;
        int Depth=this->D[U]-this->D[V]-1;
        if(Depth!=-1) REP(i,0,LOG) if(BIT(Depth,i)) U=Par[i][U];
       // debug(Depth);
        if(Depth != -1 && Par[0][U]==V){
          //  cout<<"check\n";
            return {_U,U,V};
        }
        if(Depth != -1 ) U=Par[0][U];
      //  cout<<"CHECKLCA: "<<U<<' '<<V<<endl;
        FOD(i,LOG-1,0){
            if(Par[i][U]!=Par[i][V]){
                U=Par[i][U];
                V=Par[i][V];
            }
        }
      //  cout<<"CHECKLCA: "<<U<<' '<<V<<' '<<Par[0][U]<<endl;
        return {U,V,Par[0][U]};
    }
}_LCA;
void reset_adj(void){
    FOR(i,1,N){
        adj[i].clear();
        NODE.Par[i]=i;
        NODE.CNT[i]=0;
    }
}
void make_adj(int TMP){
   // cout<<"BANADJ: "<<BanAdj[TMP].fi<<' '<<BanAdj[TMP].se<<' '<<TMP<<endl;
    bool flag=1;
    FOR(i,1,N){
        int u,v;
        tie(u,v)=Adj[i];
        int _u,_v;
        tie(_u,_v)=BanAdj[TMP];
        if(u==_u && v==_v) flag=0;
        if(!flag){
            flag=1;
            continue;
        }
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
void DFS(int u, int &U){
    for(auto v:adj[u]){
        if(D[v]) continue;
        D[v]=D[u]+1;
        if(_LCA.CNT<N-1){
            _LCA.D[v]=_LCA.D[u]+1;
            _LCA.Par[0][v]=u;
            REP(i,1,19) _LCA.Par[i][v]=_LCA.Par[i-1][_LCA.Par[i-1][v]];
            ++_LCA.CNT;
        }
        if(D[U]<D[v]) U=v;
        DFS(v,U);
    }
}
int FindSum(int u=1){
    int Sum=0;
    FOR(i,0,2){
        D[u]=1;
        DFS(u,u);
        //debug(_LCA.CNT);
        Max(Sum,D[u]);
        FOR(j,1,N) D[j]=0;
    }
    return Sum;
}
void init(void){
    cin>>N;
    reset_adj();
    FOR(i,1,N){
        cin >> Adj[i].fi >> Adj[i].se;
        if(Adj[i].fi>Adj[i].se) swap(Adj[i].fi,Adj[i].se);
        if(NODE.Set(Adj[i].fi,Adj[i].se)) continue;
        ++Cnt_BA;
        BanAdj[Cnt_BA].fi=Adj[i].fi;
        BanAdj[Cnt_BA].se=Adj[i].se;
    }
}
void process(void){
    int ANS=0;
    bool FT=1;
   // cout<<"process: "<<Cnt_BA<<' '<<BanAdj[1].fi<<' '<<BanAdj[1].se<<endl;
    while(Cnt_BA--){
        make_adj(Cnt_BA+1);
        Max(ANS,FindSum(1));
      //  cout<<"ANS: "<<ANS<<endl;
        if(FT){
            int u=BanAdj[Cnt_BA+1].fi;
            int v=BanAdj[Cnt_BA+1].se;
            int P;
            tie(u,v,P)=_LCA.FindPar(u,v);
            Cnt_BA+=2;
            BanAdj[1]={min(P,u),max(P,u)};
            BanAdj[2]={min(P,v),max(P,v)};
          //  cout<<"checkedge: "<<BanAdj[1].fi<<' '<<BanAdj[1].se<<endl;
            FT=0;
        }
        reset_adj();
    }
    cout<<ANS;
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