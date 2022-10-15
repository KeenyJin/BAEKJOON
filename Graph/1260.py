import sys
read = sys.stdin.readline
sys.setrecursionlimit(10**6)

n, m, r = map(int, read().split())
visited = [False for _ in range(n+1)]
near = [[] for _ in range(n+1)]
for _ in range(m):
    u, v = map(int, read().split())
    near[u].append(v)
    near[v].append(u)
for node in near:
    node.sort()
visit = []


def dfs(node: int):
    visit.append(node)
    visited[node] = True
    for n_ in near[node]:
        if not visited[n_]:
            dfs(n_)


dfs(r)
print(*visit)

visited = [False for _ in range(n+1)]
visited[r] = True
visit = []
q = [r]
cnt = 0
while len(q) > 0:
    cnt += 1
    p = q.pop(0)
    visit.append(p)
    for node in near[p]:
        if not visited[node]:
            visited[node] = True
            q.append(node)
print(*visit)
