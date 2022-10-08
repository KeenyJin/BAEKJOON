import sys

read = sys.stdin.readline

s = read().strip()
e = read().strip()
lst = [-1]
ans = []

for i in range(len(s)):
    if s[i] == e[lst[len(lst) - 1] + 1]:
        if lst[len(lst) - 1] + 2 == len(e):
            for _ in range(len(e) - 1):
                del lst[len(lst) - 1]  # Must delete items as a stack to prevent Run-time error.
                del ans[len(ans) - 1]
        else:
            ans.append(s[i])
            lst.append(lst[len(lst) - 1] + 1)
    elif s[i] == e[0]:
        ans.append(s[i])
        lst.append(0)
    else:
        ans.append(s[i])
        lst.append(-1)

if len(ans) == 0:
    print("FRULA")
else:
    print(*ans, sep='')
