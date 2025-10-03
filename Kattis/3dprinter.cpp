#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n; cin>>n;
    int x=1;
    int day=0;
    while(x<n) x*=2,++day;
    cout<<day+1;
}