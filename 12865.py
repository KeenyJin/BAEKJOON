import sys

read = sys.stdin.readline

'''
Below is my answer, which failed the time condition.
You must delete this remark before you submit this answer to Baekjoon. If not, time error occurs.

n, k = map(int, read().split())
wv = []
for i in range(n):
    w, v = map(int, read().split())
    if w <= k:
        wv.append([w, v])
n = len(wv)

knap = {}
for i in range(n):
    tmp = []
    if wv[i][0] not in knap:
        tmp.append(wv[i])
    elif wv[i][1] > knap[wv[i][0]]:
        tmp.append(wv[i])
    for w_ in knap:
        w = w_+wv[i][0]
        if w <= k and (w not in knap or (w in knap and knap[w] < knap[w_]+wv[i][1])):
            tmp.append([w, knap[w_]+wv[i][1]])
    for j in tmp:
        knap[j[0]] = j[1]
print(knap)
print(max(knap.values()))
'''

#========================================
# Below is the most general DP solution!

n, k = map(int, read().split())
M = [[0 for _ in range(k+1)] for _ in range(n+1)]
w, v = [0]*(n+1), [0]*(n+1)
for i in range(1, n+1):
    w[i], v[i] = map(int, read().split())
for i in range(1, n+1):
    for j in range(1, k+1):
        if w[i] > j:
            M[i][j] = M[i-1][j]
            continue
        M[i][j] = max([M[i-1][j], v[i]+M[i-1][j-w[i]]])
print(M[n][k])
