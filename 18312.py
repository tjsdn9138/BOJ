N, K = map(int, input().split())

h = 0
m = 0
s = 0
answer = 0
while h <= N:
    if K == 0 and (h < 10 or m < 10 or s < 10): answer += 1
    else:
        if str(K) in str(h): answer += 1
        elif str(K) in str(m): answer += 1
        elif str(K) in str(s): answer += 1
    
    s += 1
    if s >= 60:
        s = 0
        m += 1
    if m >= 60:
        m = 0
        h += 1
        
print(answer)