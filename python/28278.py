import sys
input = sys.stdin.readline

N = int(input())
Stack = []

for _ in range(N):
    order = list(map(int, input().split()))
    if order[0] == 1:
        Stack.append(order[1])
    elif order[0] == 2:
        if Stack:
            print(Stack.pop())
        else:
            print(-1)
    elif order[0] == 3:
        print(len(Stack))
    elif order[0] == 4:
        if not Stack:
            print(1)
        else:
            print(0)
    elif order[0] == 5:
        if Stack:
            print(Stack[-1])
        else:
            print(-1)