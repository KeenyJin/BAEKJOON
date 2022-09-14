import sys

read = sys.stdin.readline

n = int(read().strip())
weight = list(map(int, read().split()))
m = int(read().strip())
question = list(map(int, read().split()))
max_ = max(question)
dp = [0]*(max_+1)
s = {weight[0]}  # 's' is a set which contains the measurable weights via 'weight' input.
for i in range(1, n):
    tmp = {weight[i]}
    for s_ in s:
        tmp.update([s_+weight[i], abs(s_-weight[i])])
    s = s | tmp
for s_ in s:
    if s_ <= max_:
        dp[s_] = 1
for q in question:
    if dp[q]:
        print("Y", end=" ")
    else:
        print("N", end=" ")
