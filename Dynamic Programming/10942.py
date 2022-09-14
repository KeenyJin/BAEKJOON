# Must use PyPy3. Otherwise, Time-out error occurs.

import sys

read = sys.stdin.readline

n = int(read().strip())
lst = list(map(int, read().split()))
m = int(read().strip())
q = []
for _ in range(m):
    q.append(list(map(int, read().split())))
dp = [[0 for _ in range(n+1)] for _ in range(n+1)]
for i in range(1, n+1):
    dp[i][i] = 1
for i in range(2, n+1):
    for j in range(1, n+2-i):
        if lst[j-1] != lst[j+i-2]:
            continue
        if i == 2 or dp[j+1][j+i-2]:
            dp[j][j+i-1] = 1
for qq in q:
    print(dp[qq[0]][qq[1]])
