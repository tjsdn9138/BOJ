N, M = map(int, input().split())
dic = {}
for i in range(N):
    dic[i+1] = input()
dic_ = {x:y for y, x in dic.items()}

for i in range(M):
    temp = input()
    if temp.isdigit():
        print(dic[int(temp)])
    else:
        print(dic_[temp])