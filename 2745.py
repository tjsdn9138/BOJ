a, n = input().split()
b = 0
dic = {chr(i).upper(): (i-87) for i in range(ord('a'), ord('z')+1)}

for i in range(1, len(a)+1):
    if a[-i].isdigit():
        value = int(a[-i])
    else:
        value = dic[a[-i]]
    b += (int(n)**(i-1)) * value
print(b)