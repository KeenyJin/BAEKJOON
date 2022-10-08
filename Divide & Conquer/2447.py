n = int(input())
lst = [[0 for _ in range(n)] for _ in range(n)]


def func(r, c, lv):
    if lv == 1:
        lst[r][c] = 1
    else:
        nlv = lv // 3
        func(r, c, nlv)
        func(r, c+nlv, nlv)
        func(r, c+2*nlv, nlv)
        func(r+nlv, c, nlv)
        func(r+nlv, c+2*nlv, nlv)
        func(r+2*nlv, c, nlv)
        func(r+2*nlv, c+nlv, nlv)
        func(r+2*nlv, c+2*nlv, nlv)


func(0, 0, n)
for i in range(n):
    for j in range(n):
        if lst[i][j]:
            print('*', end='')
        else:
            print(' ', end='')
    print()
