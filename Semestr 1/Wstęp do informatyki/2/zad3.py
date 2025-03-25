suma = 0
iloczyn =1
n=0

while(True):
    if(suma>255 or iloczyn >500000): break

    num = int(input("podaj liczbę: "))
    suma+=num
    iloczyn*=num
    n+=1

print(f"średnia {suma/n}")
print(f"Suma: {suma}")
print(f"Iloczyn: {iloczyn}")