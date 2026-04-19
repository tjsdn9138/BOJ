import sys
A, B, C = map(int, sys.stdin.readline().split())

def solve(A, B, C):
    if B == 1:
        return A % C
    result = solve(A, B//2, C)
    if B % 2 == 0:
        return result * result % C
    else:
        return result * result * A % C
print(solve(A, B, C))