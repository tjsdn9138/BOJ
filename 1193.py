import sys
n = int(sys.stdin.readline())

line = 1
while n > line:
    n -= line
    line += 1

if line % 2 == 0:
    y = n
    x = line - n + 1
else:
    y = line - n + 1
    x = n

print(f"{y}/{x}")