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
#define sz(v) (int)v.size()
#define MAXN 100005
#define fi first
#define se second
typedef long long LL;
typedef vector<int> vi;
typedef vector<LL> vl;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
const LL MAX=1e15;
const LL MIN=-1e15;
const int NMAX=1e3+5;
bool Grid[NMAX][NMAX];
int N,M,K;
vector<pii> V;
int dx[]={0,0,1,-1,1,-1,-1,1};
int dy[]={1,-1,0,0,1,-1,1,-1};
void BFS( int X=0,  int Y=0, int D=0){
    queue< tuple<int ,int ,int > > Q;
    while(sz(V)){
        int TmpX=V.back().fi;
        int TmpY=V.back().se;
        V.pop_back();
        Q.push({TmpX,TmpY,D});
    }
    
    while(sz(Q)){
        tie(X,Y,D) = Q.front();
        Q.pop();
        if( (Grid[X][Y] && D) || D > K) continue;
        Grid[X][Y] = 1;
        REP(i,0,8){
            int _X = X + dx[i];
            int _Y = Y + dy[i];
            if(_X < 1 || _Y < 1) continue;
            if(_X > N || _Y > M) continue;
         //   cout << _X << ' ' << _Y << ' ' << D << endl;
            Q.push({_X,_Y,D+1});
        }
    }   
}
void init(void){
    cin >> N >> M >> K;
    FOR(i,1,N){
        FOR(j,1,M){
            cin >> Grid[i][j];
            if(Grid[i][j]) 
                V.push_back({i,j});
            Grid[i][j]=0;
        }
    }
    
}
void process(void){
    BFS();
 //   cout<<endl;
    FOR(i,1,N){
        FOR(j,1,M){
            cout << Grid[i][j]<<' ';
        }
        cout << endl;
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