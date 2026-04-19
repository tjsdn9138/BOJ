N = int(input())
l = list(map(int, input().split()))
MAX = max(l)

for i in range(N):
    l[i] = (l[i]/MAX)*100
print(sum(l)/N)