N = int(input())

for i in range(1000000000):
    if N == 1:
        print(1)
        break
    elif 3*(i**2)+3*i+1 < N <= 3*(i**2)+9*i+7:
        print(i+2)
        break