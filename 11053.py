cache = {}
N = int(input())
input_lst = list(map(int, input().split()))


def maxstr(x: list) -> int:
    if tuple(x) in cache:
        pass
    elif len(x) == 1:
        cache[tuple(x)] = 1
    else:
        max_result = 1
        for i in range(1, len(x)):
            if x[0] < x[i]:
                if max_result < 1 + maxstr(x[i:]):
                    max_result = 1 + maxstr(x[i:])
        cache[tuple(x)] = max_result
    return cache[tuple(x)]


min_idx = 0
max_ans = maxstr(input_lst)
for i in range(1, len(input_lst)):
    if input_lst[i] < input_lst[min_idx]:
        min_idx = i
        if max_ans < maxstr(input_lst[i:]):
            max_ans = maxstr(input_lst[i:])
print(max_ans)


#Below is the most general solution!

n = int(input())
a = list(map(int, input().split()))
dp = [0 for i in range(n)]
for i in range(n):
    for j in range(i):
        if a[i] > a[j] and dp[i] < dp[j]:
            dp[i] = dp[j]
    dp[i] += 1
print(max(dp))
