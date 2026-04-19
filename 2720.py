T = int(input())
for i in range(T):
    n = int(input())
    s_1 = s_2 = s_3 = s_4 = 0
    while n > 0:
        if n >= 25:
            s_1 = n//25
            n %= 25
        elif n >= 10:
            s_2 = n//10
            n %= 10
        elif n >= 5:
            s_3 = n//5
            n %= 5
        else:
            s_4 = n
            n = 0
    print(s_1, s_2, s_3, s_4)
