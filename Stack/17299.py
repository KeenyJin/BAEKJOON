n = int(input())
a = list(map(int, input().split()))
lst = [0 for _ in range(1000001)]
for i in a:
    lst[i] += 1
b = []
for i in a:
    b.append([i, lst[i]])
ans = [-1 for _ in range(n)]
c = []  # Stack
for i in range(n):
    idx = n-1-i
    while len(c) > 0 and b[idx][1] >= c[len(c) - 1][1]:
        del c[len(c) - 1]
    if len(c) > 0:
        ans[idx] = c[len(c) - 1][0]
    c.append(b[idx])
print(*ans, sep=' ')
