import random

position = 0
plansza=list('..a......b...e...c.d')
tura = 0

print('🦍..a......b...e...c.d')

while(True):
    print(f"\n ------------------tura {tura}--------------------- \n")
    plansza = list('..a......b...e...c.d')
    input("Rzuć kostką (ENTER)")
    ruch = random.randint(1,4)
    print(f"Wyrzuciłeś {ruch}")
    position+=ruch
    pole = plansza[position]
    plansza[position]="🦍"
    print("".join(plansza))
    tura+=1

    if(pole=="."):
        print("Trafiłeś na puste pole")
    elif(pole=='a'):
        print("Trafiłeś na pole A: Idziesz 5 pól do przodu")
        position+=5
    elif(pole=="b"):
        ileTur = random.randint(1,3)
        print(f"Trafiłeś na pole B: Czekasz {ileTur} tur")
        tura+=ileTur-1
    elif(pole=="c"):
        print("Trafiłeś na pole C: Wracasz na start")
        position = 0
    elif(pole=="d"):
        print("Trafiłeś na pole D: Wygrywasz!")
        position=0
        break
    elif (pole == "e"):
        print(f"Trafiłeś na pole D: wpadłeś w pułapkę i tracisz turę. W kolejnych turach musisz uzyskać na kostce cztery oczka, aby wyrwać się z pułapki")
        while(True):
            rzut = random.randint(1,4)
            input("Rzuć kostką (ENTER)")
            print(f"Wyrzuciłeś {rzut}")
            if(rzut==4):
                print("Wydostałeś sięz pułapki")
                break