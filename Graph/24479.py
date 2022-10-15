# PyPy3 causes a Memory error.

import sys
read = sys.stdin.readline
sys.setrecursionlimit(10**6)  # If not, Recursion error occurs.

n, m, r = map(int, read().split())
visited = [False for _ in range(n)]
visit = []
ans = [0 for _ in range(n)]
near = [[] for _ in range(n)]
for _ in range(m):
    u, v = map(int, read().split())
    near[u-1].append(v)
    near[v-1].append(u)
for n in near:
    n.sort()


def dfs(node: int):
    visit.append(node)
    ans[node-1] = len(visit)
    visited[node-1] = True
    for n in near[node-1]:
        if not visited[n-1]:
            dfs(n)


dfs(r)
print(*ans, sep='\n')
