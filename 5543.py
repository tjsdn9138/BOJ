burgur = 10000
for _ in range(3):
    burgur = min(burgur, int(input()))

drink = 10000
for _ in range(2):
    drink = min(drink, int(input()))
    
print(burgur + drink - 50)