import sys
read = sys.stdin.readline
sys.setrecursionlimit(10**6)

n = int(read())
inorder = list(map(int, read().split()))
postorder = list(map(int, read().split()))
memo = [-1 for _ in range(n+1)]
for i in range(n):
    memo[inorder[i]] = i


def preorder(ist, iend, pst, pend):
    print(postorder[pend], end=" ")
    if pend==pst:
        return
    if pend==pst+1:
        return print(postorder[pst], end=" ")
    idx = memo[postorder[pend]]
    if idx-ist:
        preorder(ist, idx-1, pst, pst+idx-ist-1)
    if iend-idx:
        preorder(idx+1, iend, pst+idx-ist, pend-1)


preorder(0, n-1, 0, n-1)
