nums=[]

while(True):
    num = int(input("Podaj liczbę: "))
    if(num%2==1):break
    nums.append(num)

min= sorted(nums)[0]
max= sorted(nums)[-1]

power = min
for i in range(max-1):power = power * min
print(f"{min}^{max} = {power}")
print(f"Najmniejsza: {min}")
print(f"Największa: {max}")