try:
    while (a := list(map(int, input().split()))): print(sum(a))
except EOFError:
    pass

