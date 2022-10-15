import sys
read = sys.stdin.readline

t = int(read().strip())
for _ in range(t):
    n = int(read().strip())
    visited = [[False for _ in range(n)] for _ in range(n)]
    s1, s2 = map(int, read().split())
    f1, f2 = map(int, read().split())
    q = [[s1, s2, 0]]
    visited[s1][s2] = True
    while len(q) > 0:
        p = q.pop(0)
        if p[0] == f1 and p[1] == f2:
            print(p[2])
            break
        nx = [1, 1, 2, 2, -1, -1, -2, -2]
        ny = [2, -2, 1, -1, 2, -2, 1, -1]
        for i in range(8):
            x = p[0]+nx[i]
            y = p[1]+ny[i]
            if 0 <= x < n and 0 <= y < n and not visited[x][y]:
                visited[x][y] = True
                q.append([x, y, p[2]+1])

