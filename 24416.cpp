#include <iostream>
using namespace std;

int f[41]={};
int cnt1=0, cnt2=0;

int fib(int n){
    if(n==1 || n==2) {
        cnt1++;
        return 1;
    }
    return fib(n-1)+fib(n-2);
}

int fibonacci(int n){
    f[1]=1; f[2]=1;
    for(int i=3;i<=n;i++) {
        cnt2++;
        f[n]=f[n-1]+f[n-2];
    }
    return f[n];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int num;
    cin>>num;
    
    fib(num); fibonacci(num);
    cout<<cnt1<<" "<<cnt2;

    return 0;
}
