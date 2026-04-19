N, K = map(int, input().split())

List = list(map(int, input().split()))
for i in range(K):
    rank = (List[i] * 100) // N
    
    if rank <= 4: print(1, end = " ")
    elif rank <= 11: print(2, end = " ")
    elif rank <= 23: print(3, end = " ")
    elif rank <= 40: print(4, end = " ")
    elif rank <= 60: print(5, end = " ")
    elif rank <= 77: print(6, end = " ")
    elif rank <= 89: print(7, end = " ")
    elif rank <= 96: print(8, end = " ")
    else: print(9, end = " ")