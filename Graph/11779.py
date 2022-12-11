import sys
import heapq
read = sys.stdin.readline
INF = sys.maxsize

N = int(read())
dist = [INF for _ in range(N+1)]
graph = [[] for _ in range(N+1)]
before = [-1 for _ in range(N+1)]
M = int(read())
for _ in range(M):
    u, v, w = map(int, read().split())
    graph[u].append([v, w])
A, B = map(int, read().split())

dist[A] = 0
h = []
heapq.heappush(h, (dist[A], A))
while h:
    d, u = heapq.heappop(h)
    if dist[u] < d:
        continue
    for v, w in graph[u]:
        if dist[v] > d + w:
            dist[v] = d + w
            before[v] = u
            heapq.heappush(h, (dist[v], v))
print(dist[B])
b = before[B]
ans = [B]
while b != -1:
    ans.append(b)
    b = before[b]
print(len(ans))
ans.reverse()
print(*ans, sep=" ")
