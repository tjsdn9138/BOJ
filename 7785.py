n = int(input())
dic = {}
List = []

for _ in range(n):
    name = input().split()[0]
    if name in dic.keys():
        dic[name] += 1
    else:
        dic[name] = 1
for i in dic.items():
    if i[1] % 2 == 1:
        List.append(i[0])
List.sort(reverse = True)

for i in List:
    print(i)