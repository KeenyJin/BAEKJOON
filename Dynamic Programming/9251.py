# Not my answer.
# https://myjamong.tistory.com/317

import sys
read = sys.stdin.readline

word1, word2 = read().strip(), read().strip()
l1, l2 = len(word1), len(word2)
cache = [0] * l2

for i in range(l1):
    cnt = 0
    for j in range(l2):
        if cnt < cache[j]:
            cnt = cache[j]
        elif word1[i] == word2[j]:
            cache[j] = cnt + 1
print(max(cache))

#=====================================================
# Below is my answer which fails the time condition.

# Longest Common Sequence Algorithm

x = input()  # Input String1
y = input()  # Input String2
n = len(x)  # Length of String1
m = len(y)  # Length of String2
cache = {}  # Dictionary of 'Common Sequence : Index of the latest character'

for i in range(n):
    _idx = []
    tmp = []
    for j in range(m):
        if x[i] == y[j]:
            _idx.append(j)
        if len(_idx) > 0:
            tmp.append([y[_idx[0]], _idx[0]])  # Insert the lowest index.
    for k in cache:
        for idx in _idx:
            if idx > cache[k] and k + y[idx] not in cache:
                tmp.append([k + y[idx], idx])
                # 'cache[k+y[idx]]=idx' causes Runtime Error, since 'cache' is in the condition.
                break  # In order to insert the lowest index.
    for t in tmp:  # Update the 'cache'.
        cache[t[0]] = t[1]

# print(cache)
if len(cache) == 0:
    print(0)  # No common sequence.
else:
    print(max(map(len, cache.keys())))  # Print the length of LCS.
