a = ["abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"]
n = input().lower()
s = 0

for i in range(len(n)):
    for ii in a :
        if n[i] in ii:
            s += a.index(ii)+3
print(s)