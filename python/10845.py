import sys
input = sys.stdin.readline

N = int(input())
que = []

for _ in range(N):
    n = input().split()
    if n[0] == "push":
        que.append(int(n[1]))
    elif n[0] == "pop":
        if len(que) == 0:
            print(-1)
        else:
            print(que.pop(0))
    elif n[0] == "size":
        print(len(que))
    elif n[0] == "empty":
        if len(que) == 0:
            print(1)
        else:
            print(0)
    elif n[0] == "front":
        if len(que) == 0:
            print(-1)
        else:
            print(que[0])
    elif n[0] == "back":
        if len(que) == 0:
            print(-1)
        else:
            print(que[-1])