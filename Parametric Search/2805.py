import sys
read = sys.stdin.readline

N, M = map(int, read().split())
height = list(map(int, read().split()))
height.sort()

lo = 0
hi = height[-1]
while hi!=lo+1:
    md = (hi+lo)//2
    l = 0
    for h in height:
       if h > md:
           l += h-md
    if l >= M:
        lo = md
    else:
        hi = md
print(lo)
