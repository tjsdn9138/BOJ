List = [input() for _ in range(3)]

for i in range(3):
    if List[i].isdigit():
        num = int(List[i]) + 3 - i
        break

if num % 3 == 0 or num % 5 == 0:
    if num % 3 == 0:
        print("Fizz", end = "")
    if num % 5 == 0:
        print("Buzz", end = "")
else:
    print(num)