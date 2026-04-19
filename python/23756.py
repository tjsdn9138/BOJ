T = int(input())

start = int(input())

answer = 0
for _ in range(T):
    target = int(input())
    
    answer += min(abs(target - start), 360 - abs(target - start))
    
    start = target

print(answer)