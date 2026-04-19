N = int(input())
answer = 0

while (N > 1):
    if N % 2 == 0: N /= 2
    else:  N += 1
        
    answer += 1
    
print(answer)