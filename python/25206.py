score = {"A+":4.5,"A0":4.0,
         "B+":3.5,"B0":3.0,
         "C+":2.5,"C0":2.0,
         "D+":1.5,"D0":1.0,"F":0.0}
List = [list(input().split()) for _ in range(20)]
hap = 0
hak_hap = 0

for i in range(20):
    if List[i][2] == "P":
        continue
    hap += score[List[i][2]] * int(List[i][1][0])
    hak_hap += int(List[i][1][0])
print(hap / hak_hap)