import sys
input = sys.stdin.readline

N = int(input())
List = []

for _ in range(N):
    lst = input().split()
    lst[1] = int(lst[1])
    lst[2] = int(lst[2])
    lst[3] = int(lst[3])
    List.append(lst)

List.sort(key = lambda x : (-x[1], x[2], -x[3], x[0]))

for i in List:
    print(i[0])