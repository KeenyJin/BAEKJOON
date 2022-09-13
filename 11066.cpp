// Top-Down Dynamic Programming Solution.
// Uses Recursive Function so takes a lot of time.
// Bottom-Up Solution is faster than below.

#include <iostream>
using namespace std;

int arr[500];
long long memo[500][500];
long long dp(int, int);

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t; cin>>t;
    for(;t>0;t--){
        int n; cin>>n;
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            for(int j=0;j<n;j++) memo[i][j]=0;
        }
        cout<<dp(0, n)<<"\n";
    }
    return 0;
}

long long dp(int x, int y){
    if(y==1) return arr[x];
    if(y==2) return arr[x]+arr[x+1];
    if(memo[x][y-1]) return memo[x][y-1];
    // dp(x, y)-sum = min( dp(x+1, y-1) , ... , dp(x, i)+dp(x+i, y-i) , ... , dp(x, y-1) )
    long long sum=0; for(int i=0;i<y;i++) sum+=arr[x+i];
    long long tmp = dp(x+1, y-1);
    long long min = tmp;
    for(int i=2;i<y-1;i++){
        tmp = dp(x, i)+dp(x+i, y-i); if(min>tmp) min=tmp;
    }
    tmp = dp(x, y-1); if(min>tmp) min=tmp;
    memo[x][y-1]=min+sum;
    return memo[x][y-1];
}
