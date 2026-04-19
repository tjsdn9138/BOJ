N = int(input())
List = [input() for _ in range(N)]
List = list(set(List))

List.sort(key = lambda x: (len(x), x))
for i in List:
    print(i)