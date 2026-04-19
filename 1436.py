n = int(input())

def check(n):
    List = []
    k = 0
    while len(List) < n:
        if "666" in str(k):
            List.append(k)
        k += 1
    return List[-1]

print(check(n))