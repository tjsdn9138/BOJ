N, M = map(int, input().split())
List_N = set([input() for _ in range(N)])
List_M = set([input() for _ in range(M)])

List = List_N & List_M
print(len(List))
for i in sorted(list(List)):
    print(i)