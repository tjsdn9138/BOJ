N = input()

a = N[: len(N) // 2]
b = N[len(N) // 2 :]

A = 0
for i in a: A += int(i)
B = 0
for i in b: B += int(i)
    
if A == B: print("LUCKY")
else: print("READY")