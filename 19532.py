a, b, c, d, e, f = map(int, input().split())
y = (a*f-d*c) / (a*e-b*d)
x = (b*f-e*c) / (b*d-a*e)

print(int(x), int(y))