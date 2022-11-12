import sys
read = sys.stdin.readline

n = int(read().strip())
stack = [0]
answer = []
lastplusnum = 0
for _ in range(n):
    num = int(read().strip())
    if lastplusnum <= num:
        for i in range(num-lastplusnum):
            stack.append(lastplusnum+i+1)
            answer.append('+')
        lastplusnum = num
        stack.pop()
        answer.append('-')
    elif stack[-1] >= num:
        while True:
            s = stack.pop()
            answer.append('-')
            if s == num:
                break
            elif s < num:
                print("NO")
                sys.exit(0)
    else:
        print("NO")
        sys.exit(0)
print(*answer, sep='\n')
