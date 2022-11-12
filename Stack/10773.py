import sys
read = sys.stdin.readline

k = int(read().strip())
stack = [0]
for _ in range(k):
    n = int(read().strip())
    if n != 0:
        stack.append(n)
    else:
        stack.pop()
print(sum(stack))
