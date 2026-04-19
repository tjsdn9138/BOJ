n = ""
while True:
    try:
        n += input().replace(" ", "")
    except EOFError:
        break
if n:    
    a = max(n, key = lambda x : n.count(x))
    List = [x for x in set(n) if n.count(x) == n.count(a)]
    for i in sorted(List):
        print(i, end = "")