#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int ans=0,n,w,h; cin>>n>>w>>h;
    for(int i=1;i<=n;++i){
        int x; cin>>x;
        if(x<=w || x<=h || x*x<=w*w+h*h)
            cout<<"DA";
        else cout<<"NE";
        cout<<endl;
    }
}