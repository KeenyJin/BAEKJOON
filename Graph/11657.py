#Bellmann-Ford Algorithm
import sys
read = sys.stdin.readline
INF = sys.maxsize

N, M = map(int, read().split())
dist = [INF for _ in range(N+1)]
edges, dist[1] = [], 0
for _ in range(M):
    edges.append(list(map(int, read().split())))

for i in range(N):  # If there is no negative cycle, only N-1 iterations are required.
    for u, v, w in edges:  # Check all edges every time.
        if dist[u] != INF and dist[v] > dist[u] + w:
            if i == N-1:  # 'dist' changed at Nth iteration, therefore negative cycle exists.
                print(-1)
                sys.exit(0)
            dist[v] = dist[u] + w

for i in range(2, N+1):
    print(-1 if dist[i]==INF else dist[i])
