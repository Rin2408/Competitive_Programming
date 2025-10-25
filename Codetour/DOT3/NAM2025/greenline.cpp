#include <bits/stdc++.h>
using namespace std;
#define tiii tuple<long long,int,int>
const int MAXN=2e5+5;
int n,K,A[MAXN];
long long P,W[MAXN],Pref[MAXN],SEG[5*MAXN],DP[MAXN][35],MAXV[MAXN],MAXINDEX[MAXN];
pair<long long,int>PAIR[MAXN];
long long GET(int id,int l,int r,int u,int v){
	if(u<=l && r<=v) return SEG[id];
	if(r<u || v<l) return LLONG_MIN;
	int m=(r+l)>>1;
	return max(GET(id<<1,l,m,u,v),GET((id<<1)+1,m+1,r,u,v));
}
void SET(int id, int l, int r, int x, long long pos){
	if(l==r){
		SEG[id]=pos;
		return;
	}
	int m=(r+l)>>1;
	if(x<=m) SET((id<<1),l,m,x,pos);
	else SET((id<<1)+1,m+1,r,x,pos);
	SEG[id]=max(SEG[id<<1],SEG[(id<<1)+1]);
}
bool check(int L){
	long long TSUM=0;
	int j=n;
	priority_queue<tiii,vector<tiii>>Q;
	for(int i=n;i>=1;--i){
		while(j>i) --j;
		while(j>0 && A[i]-A[j]<=L) --j;
		Q.push({Pref[i]-Pref[j],j+1,i});
	}
	while(Q.size()){
		long long V;
		int u,v;
		tie(V,u,v)=Q.top();
		Q.pop();
		
	}
	//cout << TSUM << ' ' << L << endl;
	return TSUM>=P;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>K>>P;
	int l=0,r=0;
    for(int i=1;i<=n;++i){
    	cin>>A[i]>>W[i];
    	Pref[i]=Pref[i-1]+W[i];
		r=max(r,A[i]);
    }
    if(Pref[n]<P){
    	cout<<-1;
    	return 0;
    }
    int L=-1;
	l=r=1;
    while(l<=r){
    	int m=l+((r-l)>>1);
    	if(check(m)){
    		L=m;
    		r=m-1;
    	//	cout<<m<<endl;
    	}
    	else l=m+1;
    }
    cout<<L;
    return 0;
}