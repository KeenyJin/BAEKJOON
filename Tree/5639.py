import sys
read = sys.stdin.readline
sys.setrecursionlimit(10**6)

preorder = []
while True:
    try:
        preorder.append(int(read()))
    except:
        break


def postorder(st, ed):
    if st==ed:
        return print(preorder[st])
    idx = st+1
    for i in range(st+1, ed+1):
        if preorder[st] < preorder[i]:
            idx = i
            break
    if idx-1 >= st+1:
        postorder(st+1, idx-1)
    if ed >= idx:
        postorder(idx, ed)
    return print(preorder[st])


postorder(0, len(preorder)-1)
