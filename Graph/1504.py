import sys
import heapq
read = sys.stdin.readline
INF = sys.maxsize

V, E = map(int, read().split())
graph = [[] for _ in range(V+1)]
for _ in range(E):
    u, v, w = map(int, read().split())
    graph[u].append([v, w])
    graph[v].append([u, w])
x, y = map(int, read().split())
s, e = 1, V


def dijkstra(start: int, end: int)-> int:
    dist = [INF]*(V+1)
    dist[start] = 0
    heap = []
    heapq.heappush(heap, (dist[start], start))
    while heap:
        d, u = heapq.heappop(heap)
        if dist[u] < d:
            continue
        if u == end:
            break
        for v, w in graph[u]:
            if dist[v] > d + w:
                dist[v] = d + w
                heapq.heappush(heap, (dist[v], v))
    return -1 if dist[end]==INF else dist[end]


xy = dijkstra(x, y)
if xy == -1:
    print(-1)
    sys.exit(0)
sx, sy = dijkstra(s, x), dijkstra(s, y)
xe, ye = dijkstra(x, e), dijkstra(y, e)
answer = []
if sx!=-1 and ye!=-1:
    answer.append(sx+xy+ye)
if sy!=-1 and xe!=-1:
    answer.append(sy+xy+xe)
print(-1 if len(answer)==0 else min(answer))
