oceny=[]

def dodajOcene(ocena, oceny):
    if (ocena < 2 or ocena > 5):
        print(f"Nieprawidłowa ocena ({ocena})")
        return
    oceny.append(ocena)

def czyZaliczonySemestr(oceny):
    for i in oceny:
        if i==2:
            print("Semestr nie zaliczony!")
            return
    print("Semestr zaliczony!")

def obliczSrednia(oceny):
    suma = 0
    for i in oceny:
        suma+=i
    return suma/len(oceny)

def ustawOceny(oceny):
    noweOceny=[]
    for i in oceny:
        if(i<obliczSrednia(oceny)):
            noweOceny.insert(0,i)
        else: noweOceny.append(i)
    return noweOceny

def wyswietlOceny(oceny):
    print("Oceny: ", end="")
    for i in oceny:
        print(i, end=", ")
    print()

dodajOcene(1, oceny)
dodajOcene(4, oceny)
dodajOcene(5, oceny)
dodajOcene(5, oceny)
dodajOcene(3, oceny)
czyZaliczonySemestr(oceny)
print(f"średnia ocen: {obliczSrednia(oceny)}")
wyswietlOceny(oceny)
ustawOceny(oceny)
dodajOcene(2,oceny)
czyZaliczonySemestr(oceny)




