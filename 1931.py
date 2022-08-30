n = int(input())
meeting = []
for i in range(n):
    meeting.append(list(map(int, input().split())))
meeting.sort(key=lambda x: (x[1], x[0]))
cnt = 1
f = meeting[0][1]
for i in range(1, n):
    if meeting[i][0] >= f:
        f = meeting[i][1]
        cnt += 1
print(cnt)
