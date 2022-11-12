import sys
read = sys.stdin.readline

near = [[] for _ in range(101)]
visited = [False for _ in range(101)]
for i in range(1, 101):
    for j in range(1, 7):
        if i+j <= 100:
            near[i].append(i+j)

ladder, snake = map(int, read().split())
for _ in range(ladder+snake):
    u, v = map(int, read().split())
    near[u] = near[v]

q = [[1, 0]]
visited[1] = True
while len(q) > 0:
    p, c = q.pop(0)
    if p == 100:
        print(c)
        break
    for n in near[p]:
        if not visited[n]:
            visited[n] = True
            q.append([n, c+1])
