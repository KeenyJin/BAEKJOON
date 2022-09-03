#include <iostream>
#define MOD 1000000007
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    long long n; cin>>n;
    long long a[2][2]={0,0,0,1}, m[2][2]={0,1,1,1};
  // 0 0  *  0 1 = 0 0
  // a b     1 1   b a+b
  // Therefore, multiply [[0,1][1,1]] (n-1) times to [[0,0][f0,f1]] -> [[0,0][fn-1,fn]]
    n--;
    while(n){
        long long tmp[2][2]={};
        if(n%2){
            for(int i=0;i<2;i++) for(int j=0;j<2;j++){
                tmp[i][j]=a[i][j]; a[i][j]=0;
            }
            for(int i=0;i<2;i++) for(int j=0;j<2;j++){
                for(int k=0;k<2;k++) a[i][j] += (tmp[i][k]*m[k][j])%MOD;
                a[i][j] %= MOD;
            }
            if(n==1) break;
        }
        for(int i=0;i<2;i++) for(int j=0;j<2;j++){
            tmp[i][j]=m[i][j]; m[i][j]=0;
        }
        for(int i=0;i<2;i++) for(int j=0;j<2;j++){
            for(int k=0;k<2;k++) m[i][j] += (tmp[i][k]*tmp[k][j])%MOD; 
            m[i][j] %= MOD;
        }
        n/=2;
    }

    cout<<a[1][1];

    return 0;
}
