import sys
read = sys.stdin.readline
sys.setrecursionlimit(10**6)

n = int(read())
child = [[] for _ in range(n+1)]
graph = [[] for _ in range(n+1)]
parent = [[] for _ in range(n+1)]
for _ in range(n):
    edges = list(map(int, read().split()))
    for i in range(1, len(edges)-1, 2):
        graph[edges[0]].append([edges[i], edges[i+1]])
q = [1]
parent[1].extend([0, 0])
while q:
    p = q.pop(0)
    for n, w in graph[p]:
        if not parent[n]:
            parent[n].extend([p, w])
            q.append(n)
for c in range(2, len(parent)):
    p, w = parent[c]
    child[p].append([c, w])


def tree_diameter(x):
    if not child[x]:
        return 0, 0
    if len(child[x])==1:
        dfs, dia = tree_diameter(child[x][0][0])
        return dfs+child[x][0][1], dia
    else:
        dfs = [0 for _ in range(len(child[x]))]
        dia = [0 for _ in range(len(child[x]))]
        for i in range(len(child[x])):
            dfs[i], dia[i] = tree_diameter(child[x][i][0])
            dfs[i] += child[x][i][1]
        a, b = dfs[0], dfs[1]
        for i in range(2, len(dfs)):
            if dfs[i] > b:
                if b > a:
                    a = b
                b = dfs[i]
            elif dfs[i] > a:
                a = dfs[i]
        return max(dfs), max(a+b, max(dia))


print(max(tree_diameter(1)))
