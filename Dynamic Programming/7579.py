# Cost = Weight, Memory = Value -> Knapsack
# Find minimum weight that value >= m

import sys

read = sys.stdin.readline

n, m = map(int, read().split())
memory = [0] + list(map(int, read().split()))
cost = [0] + list(map(int, read().split()))
max_ans = sum(cost)
dp = [[0 for _ in range(max_ans+1)] for _ in range(n+1)]
ans = max_ans
for i in range(1, n+1):
    for j in range(1, max_ans):
        if j < cost[i]:
            dp[i][j] = dp[i-1][j]
        else:
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-cost[i]]+memory[i])
        if dp[i][j] >= m:
            ans = min(ans, j)
print(ans)
