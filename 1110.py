N = input()
N_ = N
answer = 0

def cal(n):
    k = 0
    first = n[-1]
    if len(n) == 1:
        n = "0" + n
    for i in n:
        k += int(i)
    second = str(k)[-1]
    answer = first + second
    if answer[0] == "0":
        return answer[1:]
    else:
        return answer
    
while True:
    N_ = cal(N_)
    answer += 1
    if N == N_:
        print(answer)
        break