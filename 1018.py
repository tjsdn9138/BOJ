n, m = map(int, input().split())
List = [list(input()) for _ in range(n)]
answer = []

def BW(a, l):
    k = 0
    for i in range(8):
        for ii in range(8):
            if (i+ii) % 2 == 0:
                if l[i][ii] != a:
                    k += 1
            else:
                if l[i][ii] == a:
                    k += 1
    return k

for i in range(n-7):
    for ii in range(m-7):
        List_ = []
        for iii in range(8):
            temp = []
            for iv in range(8):
                temp.append(List[i+iii][ii+iv])
            List_.append(temp)
        answer.append(BW("B", List_))
        answer.append(BW("W", List_))
print(min(answer))        