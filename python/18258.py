import sys
input = sys.stdin.readline

N = int(input())
List = []
index = 0

for _ in range(N):
    n = input().split()
    
    if n[0] == 'push':
        List.append(n[1])
    elif n[0] == 'size':
        print(len(List) - index)
    elif n[0] == 'empty':
        if len(List) - index == 0:
            print(1)
        else:
            print(0)
    elif len(List) - index == 0:
        print(-1)
    elif n[0] == 'pop':
        print(List[index])
        index += 1
    elif n[0] == 'front':
        print(List[index])
    elif n[0] == 'back':
        print(List[-1])