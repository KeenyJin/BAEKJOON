import sys
read = sys.stdin.readline

n, m = map(int, read().split())
visited = [[False for _ in range(m)] for _ in range(n)]
mapp = []
for _ in range(n):
    mapp.append(read().strip())
visited[0][0] = True
q = [[0, 0, 1]]
while len(q) > 0:
    p = q.pop(0)
    if p[0] == n-1 and p[1] == m-1:
        print(p[2])
        break
    if p[0] > 0 and mapp[p[0]-1][p[1]] == '1' and visited[p[0]-1][p[1]] == False:
        visited[p[0]-1][p[1]] = True
        q.append([p[0]-1, p[1], p[2]+1])
    if p[0] < n-1 and mapp[p[0]+1][p[1]] == '1' and visited[p[0]+1][p[1]] == False:
        visited[p[0]+1][p[1]] = True
        q.append([p[0]+1, p[1], p[2]+1])
    if p[1] > 0 and mapp[p[0]][p[1]-1] == '1' and visited[p[0]][p[1]-1] == False:
        visited[p[0]][p[1]-1] = True
        q.append([p[0], p[1]-1, p[2]+1])
    if p[1] < m-1 and mapp[p[0]][p[1]+1] == '1' and visited[p[0]][p[1]+1] == False:
        visited[p[0]][p[1]+1] = True
        q.append([p[0], p[1]+1, p[2]+1])
