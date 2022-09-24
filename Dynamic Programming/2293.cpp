#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, k; cin>>n>>k;
    int *coin = new int[n];
    int *dp = new int[k+1];
    for(int i=0;i<n;i++) cin>>coin[i];
    sort(coin, coin+n);
    dp[0] = 1;
    for(int i=1;i<=k;i++){
        if(i % coin[0] == 0) dp[i] = 1;
        else dp[i] = 0;
    }
    for(int i=1;i<n;i++){
        if(coin[i] > k) break;
        for(int j=0;j+coin[i]<=k;j++) dp[j+coin[i]] += dp[j];
    }
    
    cout<<dp[k];

    delete[] coin, dp;
    return 0;
}
