import sys
read = sys.stdin.readline

n, m, r = map(int, read().split())
visited = [False for _ in range(n+1)]
near = [[] for _ in range(n+1)]
for _ in range(m):
    u, v = map(int, read().split())
    near[u].append(v)
    near[v].append(u)
for node in near:
    node.sort()
visited[r] = True
ans = [0 for _ in range(n)]
q = [r]
cnt = 0
while len(q) > 0:
    cnt += 1
    p = q.pop(0)
    ans[p-1] = cnt
    for node in near[p]:
        if not visited[node]:
            visited[node] = True
            q.append(node)
print(*ans, sep='\n')
