import sys
N = int(sys.stdin.readline())
List = [int(sys.stdin.readline()) for _ in range(N)]
List = sorted(List)

for i in List:
    print(i)