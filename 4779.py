def kan(n):
    if n == 1:
        return "-"
    else:
        return kan(n // 3) + " " * (n // 3) + kan(n // 3)
    
while True:
    try:
        print(kan(3 ** int(input())))
    except:
        break