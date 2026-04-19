Str = input()
num = 1
total = 0
var = 0

for i in Str[:-1]:

    if i == '*':
        var = num
    else:
        total += int(i) * num

    if num == 1:
        num = 3
    else:
        num = 1
        
total += int(Str[-1])

for i in range(10):
    if (total + i * var) % 10 == 0:
        print(i)
