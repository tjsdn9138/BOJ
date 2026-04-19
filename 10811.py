N, M = map(int, input().split())
List = [i+1 for i in range(N)]

for i in range(M):
    i, j = map(int, input().split())
    for k in range((j-i+1) // 2):
        List[i-1+k], List[j-1-k] = List[j-1-k], List[i-1+k]
print(*List)