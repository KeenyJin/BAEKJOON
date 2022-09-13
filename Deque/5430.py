import sys
from collections import deque

read = sys.stdin.readline

n = int(read())
for _ in range(n):
    order = read().strip()
    size = int(read())
    arr = deque(read().rstrip()[1:-1].split(','))
    if size == 0:
        arr = []
    error = False
    rev = 0
    while len(order) != 0:
        if order[0] == 'D':
            if size == 0:
                error = True
                break
            if rev % 2 == 0:
                arr.popleft()
            else:
                arr.pop()
            size -= 1
        elif order[0] == 'R':
            rev += 1  # Reverse func takes a long time so do not use it. Instead, use var 'rev'.
        order = order[1:]
    if error:
        print('error')
        continue
    ans = '['
    if size > 0 and rev % 2 == 1:
        arr.reverse()
    for i in range(size):
        ans += arr.popleft()
        if i != size-1:
            ans += ','
    ans += ']'
    print(ans)
