def znajdzmin(tablica, wartosc):
    temp = []
    for i in tablica:
        if i > wartosc:
            temp.append(i)
    return sorted(temp)[0]

def usunElementy(tablica, wartosc):
    while (wartosc in tablica):
        tablica.remove(wartosc)
    return tablica

n = 5
liczby = []

for i in range(n):
    liczby.append(int(input(f"Podaj liczbę ({i+1}/{n}): ")))

print(znajdzmin(liczby, 3))
print(usunElementy(liczby, 5))