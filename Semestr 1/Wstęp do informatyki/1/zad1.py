from random import choice

print("""
0 - papier
1 - nożyce
2 - kamień""")
choice_p1 = int(input("Podaj swój symbol (gracz 1): "))
choice_p2 = int(input("Podaj swój symbol (gracz 2): "))

if((choice_p1 not in [0,1,2]) or (choice_p2 not in [0,1,2])):
    print("Nieprawidłowe dane wejściowe")
    quit()

if(choice_p1==choice_p2):
    print("Remis")

elif (choice_p1==0):
    if(choice_p1==1): print("Wygrał gracz nr.2")
    else: print("wygrał gracz nr.1")
elif(choice_p1==1):
    if(choice_p2==0): print("Wygrał gracz nr.1")
    else: print("wygrał gracz nr.2")
else:
    if(choice_p2==0): print("Wygrał gracz nr.1")
    else: print("Wygrał gracz nr.2")



