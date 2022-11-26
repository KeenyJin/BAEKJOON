# Not my solution.
# https://sungmin-joo.tistory.com/33

import sys
import heapq
read = sys.stdin.readline
INF = sys.maxsize

V, E = map(int, read().split())
K = int(read().strip())
graph = [[] for _ in range(V+1)]
for _ in range(E):
    u, v, w = map(int, read().split())
    graph[u].append([v, w])
dist = [INF]*(V+1)

heap = []
dist[K] = 0
heapq.heappush(heap, (dist[K], K))
while heap:
    d, u = heapq.heappop(heap)
    if dist[u] < d:
        continue
    for v, w in graph[u]:
        if dist[v] > d + w:
            dist[v] = d + w
            heapq.heappush(heap, (dist[v], v))
for i in range(1, V+1):
    print("INF" if dist[i]==INF else dist[i])
