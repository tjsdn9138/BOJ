N = int(input())
List = [input().split() for _ in range(N)]

List.sort(key = lambda x: int(x[0]))
for i in List:
    print(i[0], i[1])