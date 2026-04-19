import sys
stack = []
for _ in range(int(sys.stdin.readline())):
    n = sys.stdin.readline().split()
    if "push" in n:
        stack.append(n[1])
    elif "pop" == n[0]:
        if len(stack) != 0:
            print(stack[-1])
            stack.pop()
        else:
            print(-1)
    elif "size" == n[0]:
        print(len(stack))
    elif "empty" == n[0]:
        if len(stack) == 0:
            print(1)
        else:
            print(0)
    elif "top" == n[0]:
        if len(stack) != 0:
            print(stack[-1])
        else:
            print(-1)
