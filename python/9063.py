import sys
N = int(sys.stdin.readline())
a = [list(map(int, sys.stdin.readline().split())) for i in range(N)]
x = []; y = []
for i in range(N):
    x.append(a[i][0])
    y.append(a[i][1])
print((max(y)-min(y))*(max(x)-min(x)))