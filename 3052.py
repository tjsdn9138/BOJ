List = []
num = 0
for i in range(10):
    a = int(input()) % 42
    if a not in List:
        num += 1
        List.append(a)
print(num)
