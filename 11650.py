import sys
N = int(sys.stdin.readline())
List = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

List.sort(key = lambda x: (x[0], x[1]))
for i in List:
    print(i[0], i[1])