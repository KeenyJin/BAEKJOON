#include <iostream>
#define MOD 1000000007
using namespace std;

//https://rebro.kr/105
//Fermet's Litte Theorem: a^(p-1) mod p = 1 if gcd(a, p)=1.
// -> x/a = x/a * a^(p-1) = x * a^(p-2) (mod p)
//Therefore, nCk = n!/((n-k)!k!) = n!/(n-k)! * (k!)^(p-2) (mod p)

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, K; cin>>N>>K;
    long long a=1, b=1;
    for(int i=N-K+1;i<=N;i++) a=(a*i)%MOD; //a = N!/(N-k)! mod 1000000007
    for(int i=1;i<=K;i++) b=(b*i)%MOD; // b = K! mod 1000000007
    int c = MOD - 2;
    while(c>0){
        if(c%2) a = (a*b)%MOD;
        c /= 2;
        b = (b*b)%MOD;
    } //-> a = N!/(N-K)! * (K!)^(MOD-2) mod 1000000007

    cout<<a;

    return 0;
}
