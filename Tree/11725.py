import sys
read = sys.stdin.readline

n = int(read())
graph = [[] for _ in range(n+1)]
parent = [-1 for _ in range(n+1)]
for _ in range(n-1):
    u, v = map(int, read().split())
    graph[u].append(v)
    graph[v].append(u)
q = [1]
parent[1] = 0
while q:
    p = q.pop(0)
    for n in graph[p]:
        if parent[n] == -1:
            parent[n] = p
            q.append(n)
parent = parent[2:]
print(*parent, sep='\n')
