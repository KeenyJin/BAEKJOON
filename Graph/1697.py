import sys
read = sys.stdin.readline

n, k = map(int, read().split())
visited = [False for _ in range(10**6)]
visited[n] = True
q = [[n, 0]]
while len(q) > 0:
    p = q.pop(0)
    if p[0] == k:
        print(p[1])
        break
    if p[0] > 0 and not visited[p[0]-1]:
        visited[p[0]-1] = True
        q.append([p[0]-1, p[1]+1])
    if not visited[p[0]+1]:
        visited[p[0]+1] = True
        q.append([p[0]+1, p[1]+1])
    if p[0] < k and not visited[2*p[0]]:
        visited[2*p[0]] = True
        q.append([2*p[0], p[1]+1])
