# PyPy3 -> Memory Error.
# Python3 -> Pass.

import sys
read = sys.stdin.readline
sys.setrecursionlimit(10**6)


def dfs(node: int, n: list, v: list, c:list, c_: int):  # n: near, v: visited, c: color, c_: red/blue(1/-1)
    c[node] = c_*(-1)
    for n_ in n[node]:
        if not v[n_]:
            v[n_] = True
            dfs(n_, n, v, c, c_*(-1))


T = int(read().strip())
for _ in range(T):
    V, E = map(int, read().split())
    near = [[] for _ in range(V+1)]
    edge = []
    visited = [False for _ in range(V+1)]
    for _ in range(E):
        u, v = map(int, read().split())
        edge.append([u, v])
        near[u].append(v)
        near[v].append(u)
    color = [0 for _ in range(V+1)]

    start, check = 1, 1
    while check <= V:
        visited[start] = True
        dfs(start, near, visited, color, 1)
        for c in range(check, V+1):  # If the graph is separate, all sub-graphs must be searched.
            if visited[c]:
                check = c + 1
            else:
                start = c
                break

    yes = True
    for e in edge:
        if color[e[0]] == color[e[1]]:
            yes = False
            break
    if yes:
        print("YES")
    else:
        print("NO")
