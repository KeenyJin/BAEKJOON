import sys
read = sys.stdin.readline

n = int(read().strip())
visited = [[False for _ in range(n)] for _ in range(n)]
mapp = []
ans = []
for _ in range(n):
    mapp.append(read().strip())
for i in range(n):
    for j in range(n):
        if mapp[i][j] == '1' and visited[i][j] == False:
            visited[i][j] = True
            q = [[i, j]]
            cnt = 0
            while len(q) > 0:
                p = q.pop(0)
                cnt += 1
                if p[0] > 0 and mapp[p[0]-1][p[1]] == '1' and visited[p[0]-1][p[1]] == False:
                    visited[p[0]-1][p[1]] = True
                    q.append([p[0]-1, p[1]])
                if p[0] < n-1 and mapp[p[0]+1][p[1]] == '1' and visited[p[0]+1][p[1]] == False:
                    visited[p[0]+1][p[1]] = True
                    q.append([p[0]+1, p[1]])
                if p[1] > 0 and mapp[p[0]][p[1]-1] == '1' and visited[p[0]][p[1]-1] == False:
                    visited[p[0]][p[1]-1] = True
                    q.append([p[0], p[1]-1])
                if p[1] < n-1 and mapp[p[0]][p[1]+1] == '1' and visited[p[0]][p[1]+1] == False:
                    visited[p[0]][p[1]+1] = True
                    q.append([p[0], p[1]+1])
            ans.append(cnt)
ans.sort()
print(len(ans))
print(*ans, sep='\n')
