import sys
read = sys.stdin.readline

while True:
    sentence = read()
    if sentence == ".\n":
        break
    stack = []
    check = True
    for s in sentence:
        if s == '(' or s == '[':
            stack.append(s)
        elif (s == ')' or s == ']') and len(stack) == 0:
            print("no")
            check = False
            break
        elif s == ')' and stack[-1] == '(':
            stack.pop()
        elif s == ']' and stack[-1] == '[':
            stack.pop()
        elif s == ')' or s == ']':
            print("no")
            check = False
            break
    if check and len(stack) == 0:
        print("yes")
    elif check:
        print("no")
