import sys

read = sys.stdin.readline

n = int(read())
w = []
for i in range(n):
    w.append(list(map(int, read().split())))
w.sort(key=lambda x: x[0])  # Sort by A_num.
w_b = list(map(lambda x: x[1], w))  # Make a list of B sorted by A.
dp = [0] * n
for i in range(n):  # LIS of B is the maximum of survived wires.
    for j in range(i):
        if w_b[i] > w_b[j] and dp[i] < dp[j]:
            dp[i] = dp[j]
    dp[i] += 1
print(n-max(dp))
