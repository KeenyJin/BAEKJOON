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
