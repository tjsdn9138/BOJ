T = int(input())

for _ in range(T):
    a, b = map(int, input().split())
    for i in range(min(a, b),0,-1):
        if a % i == 0 and b % i == 0:
            k = i
            break
    print(int(a*b/k))