N, K = map(int, input().split())
List = [int(input()) for _ in range(N)]
List.sort(reverse = True)
result = 0

for i in List:
    result += K // i
    K %= i

print(result)