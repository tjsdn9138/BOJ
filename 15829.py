N = int(input())
Str = input()
answer = 0

for i in range(N):
    num = ord(Str[i]) - ord('a') + 1

    answer += (31**i) * num

print(answer % 1234567891)