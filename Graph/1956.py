# Floyd-Warshall Algorithm
import sys
read = sys.stdin.readline
INF = sys.maxsize

n, m = map(int, read().split())
graph = [[INF for _ in range(n)] for _ in range(n)]
for i in range(n):
    graph[i][i] = 0
for _ in range(m):
    u, v, w = map(int, read().split())
    graph[u-1][v-1] = w
for i in range(n):
    for j in range(n):
        for k in range(n):
            if graph[j][i] != INF and graph[i][k] != INF \
                and graph[j][k] > graph[j][i] + graph[i][k]:
                graph[j][k] = graph[j][i] + graph[i][k]
ans = INF
for i in range(n):
    for j in range(n):
        if i!=j and graph[i][j]!=INF and graph[j][i]!=INF \
            and ans > graph[i][j] + graph[j][i]:
            ans = graph[i][j] + graph[j][i]
print(-1 if ans==INF else ans)
