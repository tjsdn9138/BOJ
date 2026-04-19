N, K = map(int, input().split())
List = list(range(1, N+1))
index = K - 1

print("<", end = "")
while len(List) > 1:
    if index > len(List) - 1:
        index %= len(List)
    
    print(f"{List.pop(index)}, ", end = "")

    index += K - 1
print(f"{List[0]}>")