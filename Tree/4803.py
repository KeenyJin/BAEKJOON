import sys
read = sys.stdin.readline

case = 0
while True:
    n, m = map(int, read().split())
    if not n and not m:
        break
    case += 1
    tree = 0
    cycle = False
    graph = [0 for _ in range(n+1)]
    for _ in range(m):
        u, v = map(int, read().split())
        if not graph[u] and not graph[v]:
            tree += 1
            graph[u], graph[v] = tree, tree
        elif not graph[u]:
            graph[u] = graph[v]
        elif not graph[v]:
            graph[v] = graph[u]
        elif graph[u] == graph[v] or graph[u] == -1 or graph[v] == -1:
            if graph[u] == -1 and graph[v] == -1:
                continue
            cycle = True
            g = graph[v]
            if graph[u] != -1:
                g = graph[u]
            for i in range(1, len(graph)):
                if graph[i] == g:
                    graph[i] = -1
        else:
            g = graph[v]
            for i in range(1, len(graph)):
                if graph[i] == g:
                    graph[i] = graph[u]
    ans = 0
    graph = graph[1:]
    for g in graph:
        if not g:
            ans += 1
    s = set(graph)
    t = len(s)
    if ans:
        t -= 1
    if cycle:
        t -= 1
    ans += t
    print("Case %d: "%case, end="")
    if not ans:
        print("No trees.")
    elif ans == 1:
        print("There is one tree.")
    else:
        print("A forest of %d trees."%ans)
