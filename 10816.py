N = int(input())
List_n = list(map(int, input().split()))
M = int(input())
List_m = list(map(int, input().split()))
dic = {}

for i in List_n:
    if i in dic.keys():
        dic[i] += 1
    else:
        dic[i] = 1

for i in List_m:
    if i in dic.keys():
        print(dic[i], end = " ")
    else:
        print(0, end = " ")