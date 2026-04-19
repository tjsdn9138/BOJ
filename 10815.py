N = int(input())
List_n = list(map(int, input().split()))
M = int(input())
List_m = list(map(int, input().split()))
gyo = set(List_n) & set(List_m)

for i in List_m:
    if i in gyo:
        print(1, end = " ")
    else:
        print(0, end = " ")