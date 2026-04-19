a = input()

for i in range(len(a)):
    if a[i].isupper() == 1:
        print(a[i].lower(), end = '')
    else:
        print(a[i].upper(), end = '')