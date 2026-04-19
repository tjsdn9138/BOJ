c_al = ["c=", "c-", "d-", "lj", "nj", "s=", "z="]
n = input()
minus = 0

if "dz=" in n:
    minus += n.count("dz=")
for i in range(len(c_al)):
    if c_al[i] in n:
        minus += (n.count(c_al[i]))
print(len(n)-minus)