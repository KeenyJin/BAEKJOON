import sys
read = sys.stdin.readline
INF = sys.maxsize

n = int(read())
m = int(read())
graph = [[INF for _ in range(n)] for _ in range(n)]
before = [[-1 for _ in range(n)] for _ in range(n)]
for i in range(n):
    graph[i][i] = 0
for _ in range(m):
    u, v, w = map(int, read().split())
    if graph[u-1][v-1] > w:
        graph[u-1][v-1] = w
for i in range(n):
    for j in range(n):
        for k in range(n):
            if graph[j][i] != INF and graph[i][k] != INF \
                and graph[j][k] > graph[j][i] + graph[i][k]:
                graph[j][k] = graph[j][i] + graph[i][k]
                before[j][k] = i
for i in range(n):
    for j in range(n):
        print(0 if graph[i][j]==INF else graph[i][j], end=" ")
    print()


def print_route(x: int, y: int, z: list):
    if before[x][y] == -1:
        z.append(x+1)
    else:
        print_route(x, before[x][y], z)
        print_route(before[x][y], y, z)


for i in range(n):
    for j in range(n):
        if graph[i][j] == INF or graph[i][j] == 0:
            print(0)
        else:
            ans = []
            print_route(i, j, ans)
            ans.append(j+1)
            print(len(ans), *ans, sep=" ")
