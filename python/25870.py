s = input()

flag = -1
for i in s:
    if s.count(i) % 2 == 0:
        if flag == -1 or flag == 0: flag = 0
        else: flag = 2
    elif s.count(i) % 2 == 1:
        if flag == -1 or flag == 1: flag = 1
        else: flag = 2      
print(flag)