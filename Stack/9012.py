import sys
read = sys.stdin.readline

T = int(read().strip())
for _ in range(T):
    s_ = read().strip()
    stack = []
    check = True
    for s in s_:
        if s == '(':
            stack.append(s)
        elif '(' in stack:
            stack.pop()
        else:
            print("NO")
            check = False
            break
    if check and len(stack) == 0:
        print("YES")
    elif check:
        print("NO")
