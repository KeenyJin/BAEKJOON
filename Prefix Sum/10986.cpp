#include <iostream>
using namespace std;

int n, m, num;
long long rest[1000]={}; //The number of prefix sum that %m==index.
long long sum=0, ans; //Type must be long long.

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>num;
        sum+=num; sum%=m; //sum%=m, if not 'long long overflow'.
        rest[sum]++;
    }
    ans = rest[0];
    for(int i=0;i<m;i++) ans += rest[i] * (rest[i]-1)/2; //nC2
    cout<<ans;

    return 0;
}
