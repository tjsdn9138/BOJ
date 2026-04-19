N = int(input())

answer = 0
N = 1000 - N

answer += N // 500
N %= 500
answer += N // 100
N %= 100
answer += N // 50
N %= 50
answer += N // 10
N %= 10
answer += N // 5
N %= 5
answer += N

print(answer)