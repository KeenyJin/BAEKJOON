import sys

read = sys.stdin.readline

n = int(read().strip())
pp = []  # Stack
ans1 = 0  # People smaller than me that I can see.
ans2 = [0 for _ in range(n)]  # People same/taller than me that I can see.
for i in range(n):
    p = int(read().strip())
    while len(pp) > 0 and p > pp[len(pp) - 1][0]:
        del pp[len(pp) - 1]
        ans1 += 1
    if len(pp) > 0 and p <= pp[len(pp) - 1][0]:
        if p == pp[len(pp) - 1][0]:
            ans2[i] += ans2[pp[len(pp) - 1][1]]
        ans2[i] += 1
    pp.append([p, i])
print(ans1 + sum(ans2))
