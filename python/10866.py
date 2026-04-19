import sys
input = sys.stdin.readline

N = int(input())
deq = []

for _ in range(N):
    n = input().split()
    if "push" in n[0]:
        if "front" in n[0]:
            deq.insert(0, n[1])
        else:
            deq.append(n[1])
    elif "pop" in n[0]:
        if len(deq) == 0:
            print(-1)
        elif "front" in n[0]:
            print(deq.pop(0))
        else:
            print(deq.pop())
    elif n[0] == "size":
        print(len(deq))
    elif n[0] == "empty":
        if len(deq) == 0:
            print(1)
        else:
            print(0)
    elif n[0] == "front":
        if len(deq) == 0:
            print(-1)
        else:
            print(deq[0])
    elif n[0] == "back":
        if len(deq) == 0:
            print(-1)
        else:
            print(deq[-1])