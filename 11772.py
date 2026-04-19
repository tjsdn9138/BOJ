N = int(input())

total = 0

for _ in range(N):
    a = int(input())
    b = a % 10
    a //= 10
    
    total += (int)(a**b)
   
print(total)