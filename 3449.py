T = int(input())

for _ in range(T):
    a = input()
    b = input()
    
    size = len(a)
    answer = 0
    for i in range(size):
        if a[i] != b[i]: answer += 1
            
    print("Hamming distance is " + str(answer) + ".")