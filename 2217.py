N = int(input())
List = [int(input()) for _ in range(N)]
answer = []

List.sort()

while List:
    answer.append(len(List) * List.pop(0))

print(max(answer))