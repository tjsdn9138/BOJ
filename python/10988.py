n = input()
a = 1

for i in range(len(n) // 2):
    if n[i] != n[-i-1]:
        a = 0
        break
print(a)