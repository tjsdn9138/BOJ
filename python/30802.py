N = int(input())
List = list(map(int, input().split()))
T, P = map(int, input().split())
answer = 0

for i in List:
    answer += i // T

    if i % T != 0:
        answer += 1

a= N // P
b = N % P    

print(answer)
print(f"{a} {b}")