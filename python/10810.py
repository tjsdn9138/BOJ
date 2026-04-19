N, M = map(int, input().split())
a = []

for i in range(N):
    a.append(0)
for i in range(M):
    b, c, d = map(int, input().split())
    for j in range(b-1, c):
        a[j] = d
for i in range(N):
    print(a[i])