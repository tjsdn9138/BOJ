N, M = map(int, input().split())
S = set([input() for _ in range(N)])
List = [input() for _ in range(M)]
k = 0

for i in List:
    if i in S:
        k += 1
print(k)