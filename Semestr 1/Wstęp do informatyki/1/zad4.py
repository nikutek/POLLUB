from math import sqrt
a = int(input("Podaj a: "))
b = int(input("Podaj b: "))
c = int(input("Podaj c: "))

delta = b**2 - 4*a*c

if(delta<0):
    print("Brak pierwiastków")
elif(delta==0):
    x1 = (-b) /(2*a)
    print("x1 = "+str(x1))
else:
    x1 = (-b - sqrt(delta))/2*a
    x2 = (-b + sqrt(delta))/2*a
    print("x1 = "+str(x1))
    print("x2 = "+str(x2))