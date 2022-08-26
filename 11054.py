#DP LIS + ReverseLIS(=Longest Decreasing Subsequence) -> Find Max

N = int(input())
lst = list(map(int, input().split()))
dp1 = [0]*N
dp2 = [0]*N
dp = [0]*N

for i in range(N):
    for j in range(i):
        if lst[i] > lst[j] and dp1[i] < dp1[j]:
            dp1[i] = dp1[j]
        if lst[N-1-i] > lst[N-1-j] and dp2[N-1-i] < dp2[N-1-j]:
            dp2[N-1-i] = dp2[N-1-j]
    dp1[i] += 1
    dp2[N-1-i] += 1
for i in range(N):
    dp[i] = dp1[i] + dp2[i] - 1

print(max(dp))
