#include <iostream>
using namespace std;

int a, b, c, rest;
long long func(int);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>a>>b>>c;
    rest = a%c;
    if(rest==0) cout<<0;
    else cout<<func(b);

    return 0;
}

long long func(int lv){
    if(lv==1) return rest;
    long long r = func(lv/2);
    r = (r*r)%c;
    if(lv%2==1) r=(r*a)%c;
    return r;
}
