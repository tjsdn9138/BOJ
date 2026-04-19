N = int(input())
List = list(map(int, input().split()))
stack = []
k = 1

while List:
    if List[0] == k:
        List.pop(0)
        k += 1
    elif stack and stack[-1] == k:
        stack.pop()
        k += 1
    else:
        stack.append(List.pop(0))
else:
    while stack:
        if stack[-1] == k:
            stack.pop()
            k += 1
        else:
            print("Sad")
            break
    else:
        print("Nice")