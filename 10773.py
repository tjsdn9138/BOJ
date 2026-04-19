K = int(input())
List = []

for _ in range(K):
    num = int(input())
    if num:
        List.append(num)
    else:
        del List[-1]
    
print(sum(List))