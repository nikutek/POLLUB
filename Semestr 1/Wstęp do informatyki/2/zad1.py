print("Kamień / Papier / nożyce")

while(True):
    p1 = input("Gracz 1: ").lower()
    p2 = input("Gracz2: ").lower()

    if(p1==p2):
        print("remis")
        continue
    elif (p1=="papier"):
        if(p2=="kamien"):
            print("Gracz 2 wygrywa")
        elif(p2=="nozyce"):
            print("gracz 1 wygrywa")
    elif (p1=="kamien"):
        if(p2=="papier"):
            print("Gracz 2 wygrywa")
        elif(p2=="nozyce"):
            print("gracz 1 wygrywa")
    elif (p1=="nozyce"):
        if(p2=="papier"):
            print("Gracz 2 wygrywa")
        elif(p2=="papier"):
            print("gracz 1 wygrywa")
    else:
        print("niewłaściwy symbol")
    break