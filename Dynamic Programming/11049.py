# C++     3000KB    40ms
# PyPy3   117232KB  1224ms
# Python3 -> Time out error

import sys

read = sys.stdin.readline

n = int(read().strip())
size = []
for _ in range(n):
    size.append(list(map(int, read().split())))

dp = [[0 for _ in range(n)] for _ in range(n)]
for i in range(n-1):
    dp[i][1] = size[i][0]*size[i][1]*size[i+1][1]
for i in range(2, n):
    for j in range(n-i):
        dp[j][i] = dp[j][0] + dp[j+1][i-1] + size[j][0]*size[j+1][0]*size[j+i][1]
        for k in range(1, i):
            dp[j][i] = min(dp[j][i], dp[j][i-k] + dp[j+i-k+1][k-1] + size[j][0]*size[j+i-k+1][0]*size[j+i][1])
print(dp[0][n-1])


'''
// Same algorithm, but implemented by C++.
#include <iostream>
using namespace std;

int arr[500][2];
int dp[500][500];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n; cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i][0]>>arr[i][1];
    for(int i=0;i<n-1;i++) dp[i][1] = arr[i][0]*arr[i][1]*arr[i+1][1];
    for(int i=2;i<n;i++){
        for(int j=0;j<n-i;j++){
            dp[j][i] = dp[j][0]+dp[j+1][i-1]+arr[j][0]*arr[j+1][0]*arr[j+i][1];
            for(int k=1;k<i;k++){
                int m = dp[j][i-k]+dp[j+i-k+1][k-1]+arr[j][0]*arr[j+i-k+1][0]*arr[j+i][1];
                if(dp[j][i]>m) dp[j][i]=m;
            }
        }
    }
    cout<<dp[0][n-1];

    return 0;
}
'''
