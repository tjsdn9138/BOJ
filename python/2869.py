A, B, V = map(int, input().split())
n = (V-A) // (A-B)

if (V-A) % (A-B) == 0:
    print(n+1)
else:
    print(n+2)