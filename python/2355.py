A, B = map(int, input().split())

if A > B:
    A, B = B, A

answer = (int)((B * B + B - A * A + A) / 2)

print(answer)