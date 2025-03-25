import random

karty = {"2":2,
         "3":3,
         "4":4,
         "5":5,
         "6":6,
         "7":7,
         "8":8,
         "9":9,
         "10":10,
         "walet":2,
         "dama":3,
         "krol":4,
         "as":11}

score1=0
score2=0

print("Gracz 1")
while(True):
    if(score1>=22):
        print("Przegrałeś!")
        print(f"Twój wynik to: {score1}")
        quit()  #czy gra powinna sie skończyć w tym momencie skoro gracz 1 przegrał?
        # break

    choice = input("Gracz 1: dobierz / pasuj\n")
    if(choice=="dobierz"):
        karta = random.choice(list(karty.keys()))
        score1+=karty.get(karta)
        print(f"wylosowana karta to {karta}")
        print(f"Twój wynik to: {score1}")
    elif(choice=="pasuj"):
        print(f"Spasowałeś. Twój wynik to: {score1}")
        break


print("\n\nGracz 2")
while(True):
    if(score2>=22):
        print("Przegrałeś!")
        print(f"Twój wynik to: {score2}")
        break

    choice = input("Gracz 2: dobierz / pasuj\n")
    if(choice=="dobierz"):
        karta = random.choice(list(karty.keys()))
        score2+=karty.get(karta)
        print(f"wylosowana karta to {karta}")
        print(f"Twój wynik to: {score2}")
    elif(choice=="pasuj"):
        print(f"Spasowałeś. Twój wynik to: {score2}")
        quit()
        # break

print("\n\n")
if (score1<=21 and score2<=21):
    if (abs(21 - score1) == abs(score2)): print("Remis")
    elif(abs(21-score1) > abs(score2)): print("wygrał gracz 2")
    else:
        print("wygrał gracz 1")
print(f"gracz 1: {score1}\ngracz 2: {score2}")