N = int(input())

List = list(map(int, input().split()))

answer = 0
for i in List:
    if i > N: answer += N
    else: answer += i

print(answer)