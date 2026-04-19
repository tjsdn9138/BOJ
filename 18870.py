import sys
input = sys.stdin.readline
N = int(input())
List = list(map(int, input().split()))
List_ = {ii : i for i, ii in enumerate(sorted(set(List)))}
dic = {x:List_[x] for x in List}

for i in List:
    print(dic[i], end = " ")