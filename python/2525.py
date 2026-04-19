A, B = map(int, input().split())
C = int(input())

B += C
while True:
    if B >= 60:
        B -= 60
        if A == 23:
            A = 0
        else:
            A += 1
    else:
        break

print(A, B)