// Without Memoization, Time-out error occurs.

#include <iostream>
using namespace std;

int n, m, arr[500][500], dp[500][500];
int dfs(int r, int c){
    if(r==n-1 && c==m-1) return 1;
    if(dp[r][c] != -1) return dp[r][c];
    dp[r][c]=0;
    if(r>0 && arr[r][c]>arr[r-1][c]) dp[r][c]+=dfs(r-1, c);
    if(c>0 && arr[r][c]>arr[r][c-1]) dp[r][c]+=dfs(r, c-1);
    if(r<n-1 && arr[r][c]>arr[r+1][c]) dp[r][c]+=dfs(r+1, c);
    if(c<m-1 && arr[r][c]>arr[r][c+1]) dp[r][c]+=dfs(r, c+1);
    return dp[r][c];
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>n>>m;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++){
        cin>>arr[i][j];
        dp[i][j]=-1;
    }
    cout<<dfs(0, 0);

    return 0;
}
