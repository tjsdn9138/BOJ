import sys
input = sys.stdin.readline

T = int(input())

def sosu(n):
    if n < 2:
        return 0
    if n == 2:
        return 1
    if n % 2 == 0:
        return 0
    for i in range(3, int(n**0.5) + 2):
        if n % i == 0:
            return 0
        
    return 1

for _ in range(T):
    n = int(input())
    while True:
        if sosu(n) == 1:
            print(n)
            break
        else:
            n += 1