N, M = map(int, input().split())
a = []
for i in range(1, N+1):
    a.append(i)

for i in range(M):
    b, c = map(int, input().split())
    d = a[b-1]
    a[b-1] = a[c-1]
    a[c-1] = d
for i in range(N):
    print(a[i], end = " ")