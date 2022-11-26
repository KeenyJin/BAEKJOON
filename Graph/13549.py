import sys
import heapq
read = sys.stdin.readline
INF = sys.maxsize

N, K = map(int, read().split())
V = 2 * max([N, K]) + 1


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
        if u < end and dist[u+1] > d+1:
            dist[u+1] = d+1
            heapq.heappush(heap, (dist[u+1], u+1))
        if u < end and dist[2*u] > d:
            dist[2*u] = d
            heapq.heappush(heap, (dist[2*u], 2*u))
        if u > 0 and dist[u-1] > d+1:
            dist[u-1] = d+1
            heapq.heappush(heap, (dist[u-1], u-1))
    return dist[end]


print(dijkstra(N, K))
