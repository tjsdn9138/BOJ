def ThreeToTen(n: str):
    degree = 0
    result = 0

    while n:
        temp = n[-1]
        if temp.isalpha():
            temp = ord(temp) - ord('A') + 10
        
        result += int(temp) * int(36**degree)
        degree += 1
        n = n[:-1]

    return result

def TenToThree(n: int):
    if n == 0:
        return '0'

    List = []
    result = ""

    while (n):
        List.append(n % 36)
        n //= 36

    for i in List[::-1]:
        if 0 <= i <= 9:
            result += str(i)
        else:
            result += chr(i + ord('A') - 10)

    return result




N = int(input())
List = [input() for _ in range(N)]
K = int(input())

total = 0
alpha = [[i, 0] for i in range(0, 36)]

for word in List:
    degree = 0
    total += ThreeToTen(word)

    for i in word[::-1]:
        if i.isalpha():
            i = ord(i) - ord('A') + 10
        alpha[int(i)][1] += int(36**degree)
        
        degree += 1

alpha.sort(key = lambda x : -((35 - x[0]) * x[1]))

for i in range(K):
    total += (35 - alpha[i][0]) * alpha[i][1]

print(TenToThree(total))