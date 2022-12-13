import sys
read = sys.stdin.readline
sys.setrecursionlimit(10**6)

n = int(read())
child = [[] for _ in range(n+1)]
for _ in range(n-1):
    u, v, w = map(int, read().split())
    child[u].append([v, w])


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
