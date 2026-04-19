import sys
input = sys.stdin.readline

n = int(input())
List = [int(input()) for _ in range(n)]
total = 0

List.sort()

if (n * 15) % 100 >= 50:
    order = (n * 15) // 100 + 1
else:
    order = (n * 15) // 100

if n == 1:
    print(List[0])
elif n == 0:
    print(0)
else:
    for i in range(order, n - order):
        total += List[i]

    if total % (n - 2 * order) >= (n - 2 * order) * 0.5:
        answer = total // (n - 2 * order) + 1
    else:
        answer = total // (n - 2 * order)

    print(answer)