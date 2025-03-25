lista=[]

def dodajLiczbe(n):
    lista.append(n)

def usunOstatniaLiczbe():
    lista.pop()

def wyswietlWynik():
    print(sum(lista))

while(True):
    wybor = int(input("1-dodaj liczbę\n2-usuń ostatnią liczbę\n3-wyświetl wynik\n0-koniec\nwybór: "))
    if (wybor == 0):
        break
    elif(wybor==1):
        liczba = int(input("Podaj liczbę (0-koniec): "))
        dodajLiczbe(liczba)
    elif(wybor==2):
        usunOstatniaLiczbe()
    elif(wybor==3):
        wyswietlWynik()
    else: print("Nieprawidłowy wybór")


