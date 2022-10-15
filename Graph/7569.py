# 
# https://velog.io/@hysong/%EB%B0%B1%EC%A4%80-7576-%ED%86%A0%EB%A7%88%ED%86%A0-%ED%8C%8C%EC%9D%B4%EC%8D%AC-python

import sys
import collections

read = sys.stdin.readline
di = [1, -1, 0, 0, 0, 0]
dj = [0, 0, 1, -1, 0, 0]
dk = [0, 0, 0, 0, 1, -1]
M, N, H = map(int, read().split())
graph = [[list(map(int, read().split())) for _ in range(N)] for _ in range(H)]
queue = collections.deque()

# push all the ripe tomatoes into queue.
for k in range(H):
    for i in range(N):
        for j in range(M):
            if graph[k][i][j] == 1:
                queue.append((k, i, j))

# ripen the other tomatoes.
while queue:  # bfs
    k, i, j = queue.popleft()
    for l in range(6):
        ni = i + di[l]
        nj = j + dj[l]
        nk = k + dk[l]
        if 0 <= ni < N and 0 <= nj < M and 0 <= nk < H and graph[nk][ni][nj] == 0:
            graph[nk][ni][nj] = graph[k][i][j] + 1
            queue.append((nk, ni, nj))

# calculate the answer.
ans = 0
for height in graph:
    for row in height:
        if 0 in row:
            print(-1)
            sys.exit(0)
        m = max(row)
        if ans < m:
            ans = m
print(ans-1)
