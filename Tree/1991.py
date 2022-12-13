import sys
read = sys.stdin.readline
sys.setrecursionlimit(10**6)

n = int(read())
child = [[] for _ in range(n)]
for _ in range(n):
    edge = read().split()
    child[ord(edge[0])-65].extend(edge[1:])


def preorder(x):
    print(x, end="")
    for c in child[ord(x)-65]:
        if c!='.':
            preorder(c)
def inorder(x):
    l = child[ord(x)-65]
    if l and l[0]!='.':
        inorder(l[0])
    print(x, end="")
    if l and l[1]!='.':
        inorder(l[1])
def postorder(x):
    for c in child[ord(x)-65]:
        if c!='.':
            postorder(c)
    print(x, end="")


preorder('A')
print()
inorder('A')
print()
postorder('A')
