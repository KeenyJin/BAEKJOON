import sys
read = sys.stdin.readline

n = int(read().strip())
stack = []
ans = 0
for _ in range(n):
    block = int(read().strip())
    if len(stack) == 0:
        stack.append(block)
        if ans < block:
            ans = block
    elif stack[len(stack)-1] <= block:
        stack.append(block)
    else:
        cnt = 0
        while len(stack) > 0 and stack[len(stack)-1] > block:
            cnt += 1
            popblock = stack.pop()
            if ans < popblock * cnt:
                ans = popblock * cnt
        stack += [block] * (cnt + 1)
cnt = 0
while len(stack) > 0:
    cnt += 1
    popblock = stack.pop()
    if ans < popblock * cnt:
        ans = popblock * cnt
print(ans)
