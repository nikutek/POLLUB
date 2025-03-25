import math
suma = 0
n=3

for i in range(n):
    num = int(input("Podaj liczbę w przedziale 1-50: "))
    if(num<10 or num>50):
        print("Nieprawidłowa liczba")
        continue
    suma+=math.pow(num,2)


print(suma)