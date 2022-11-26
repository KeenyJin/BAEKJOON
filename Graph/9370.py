import sys
import heapq
read = sys.stdin.readline
INF = sys.maxsize

T = int(read())
for _ in range(T):
    n, m, t = map(int, read().split())
    s, g, h = map(int, read().split())
    graph = [[] for _ in range(n+1)]
    for _ in range(m):
        u, v, w = map(int, read().split())
        graph[u].append([v, w])
        graph[v].append([u, w])
    dist = [INF for _ in range(n+1)]
    dist[s] = 0
    chk = [False for _ in range(n+1)]
    dest = []
    for _ in range(t):
        dest.append(int(read()))
    dest.sort()

    heap = []
    heapq.heappush(heap, (dist[s], s))
    while heap:
        d, u= heapq.heappop(heap)
        if dist[u] < d:
            continue
        for v, w in graph[u]:
            if dist[v] > d + w:
                dist[v] = d + w
                heapq.heappush(heap, (dist[v], v))
                if (u==g and v==h) or (u==h and v==g):
                    chk[v] = True
                else:
                    chk[v] = chk[u]
            elif dist[v] == d + w:
                if (u==g and v==h) or (u==h and v==g):
                    chk[v] = True
                    heapq.heappush(heap, (dist[v], v))
                elif chk[u] and not chk[v]:
                    chk[v] = True
                    heapq.heappush(heap, (dist[v], v))

    for d in dest:
        if chk[d]:
            print(d, end=" ")
    print()
