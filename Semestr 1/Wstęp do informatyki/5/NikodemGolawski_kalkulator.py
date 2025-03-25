import math

def mnozenie(a,b):
    return a*b

def dzielenie(a,b):
    return a/b

def potegowanie(a,b):
    return math.pow(a,b)

def main():

    print("Witaj w kalkulatorze")

    while(True):
        wybor = int(input("Wybierz operację (0-wyjscie\n1-mnozenie\n2-dzielenie\n3-potegowanie\n"))

        if(wybor==0):
            break

        a = int(input("Podaj a: "))
        b = int(input('Podaj b: '))

        if(wybor==1):
            print(mnozenie(a,b))
        elif (wybor==2):
            print(dzielenie(a,b))
        elif (wybor==3):
            print(potegowanie(a,b))
        else: print("Nieprawidłowy wybór!")


main()