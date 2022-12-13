import sys
read = sys.stdin.readline

n = int(read())
m = int(read())
graph = [[] for _ in range(n)]
for i in range(n):
    edge = list(map(int, read().split()))
    for j in range(n):
        if edge[j]:
            graph[i].append(j)
            graph[j].append(i)
route = list(map(int, read().split()))
for i in range(m):
    route[i] -= 1

visited = [False for _ in range(n)]
visited[route[0]] = True
arrive = [route[0]]
while arrive:
    city = arrive.pop(0)
    for c in graph[city]:
        if not visited[c]:
            visited[c] = True
            arrive.append(c)
for r in route:
    if not visited[r]:
        print("NO")
        sys.exit(0)
print("YES")
