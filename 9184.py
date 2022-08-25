cache = {}


def w(x: tuple) -> int:
    if x in cache:
        return cache[x]
    a, b, c = x
    if a <= 0 or b <= 0 or c <= 0:
        cache[x] = 1
    elif a > 20 or b > 20 or c > 20:
        cache[x] = w((20, 20, 20))
    elif a < b < c:
        cache[x] = w((a, b, c - 1)) + w((a, b - 1, c - 1)) - w((a, b - 1, c))
    else:
        cache[x] = w((a - 1, b, c)) + w((a - 1, b - 1, c)) + w((a - 1, b, c - 1)) \
                   - w((a - 1, b - 1, c - 1))
    return cache[x]


while 1:
    tu = tuple([int(i) for i in input().split()])
    if tu == (-1, -1, -1):
        break
    print("w(%d, %d, %d) = %d" % (tu[0], tu[1], tu[2], w(tu)))
