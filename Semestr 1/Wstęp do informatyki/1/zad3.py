num = int(input("Podaj liczbę w zakresie 0-999: "))

if(num<0 or num > 999):
    print("Nieprawidłowa liczba")
    quit()

setki = num//100%10
dziesiatki = num//10%10
jednosci = num%10
suma=setki+dziesiatki+jednosci

print("Suma cyfr:" + str(suma) + ", setki:"+str(setki)+ ", dziesiątki:"+str(dziesiatki)+", jednosci" + str(jednosci))
