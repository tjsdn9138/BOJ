import math
dic = {x-87: chr(x).upper() for x in range(ord("a"), ord("z")+1)}
N, B = map(int, input().split())
k = int(math.log(N, B))
answer = ""

while k >= 0:
    if N >= B**k:
        if N//(B**k) < 10:
            answer += str(N//(B**k))
        else:
            answer += dic[N//(B**k)]
        N %= B**k
        k -= 1
    else:
        answer += "0"
        k -= 1
print(answer)