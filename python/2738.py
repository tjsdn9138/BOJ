N, M = map(int, input().split())
a = []
temp = []

for i in range(N):
    a += list(map(int, input().split()))
for i in range(N):
    temp += list(map(int, input().split()))
for i in range(N * M):
    a[i] += temp[i]
    print(a[i], end = ' ')
    if (i+1) % M == 0:
        print()