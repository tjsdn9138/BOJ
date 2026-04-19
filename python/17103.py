import sys
input = sys.stdin.readline

T = int(input())

prime = [True] * 1000001
prime[0] = prime[1] = False
for i in range(2, 1000):
    for ii in range(i*i, 1000001, i):
        prime[ii] = False


for _ in range(T):
    result = 0
    Num = int(input())
    
    for num in range(2, Num//2 + 1):
        if prime[num] and prime[Num - num]:
            result += 1
    
    sys.stdout.write(f"{result}\n")