import random

class Gra:
    def __init__(self, akthp, maxhp, zloto, poziom, exp, napoje):
        self.akthp = akthp
        self.maxhp = maxhp
        self.zloto = zloto
        self.poziom = poziom
        self.exp = exp
        self.napoje = napoje
        self.STARTING_HP = maxhp
        self.obrazenia = 10
        self.expDoNastepnegoPoziomu=100

    def sleep(self):
        self.akthp = self.maxhp
        print(f"Uleczono do {self.akthp} zdrowia")

    def buyHealthPotion(self):
        if self.zloto >=5:self.napoje.append("healthPotion")
        else: print("Brak złota")

    def startFight(self, difficulty):
        if(difficulty==1):
            handicap = 0.7
        elif(difficulty==2):
            handicap = 1.2
        elif(difficulty==3):
            handicap = 3
        oponentMaxHP = self.STARTING_HP*handicap*(random.randint(8,12)/10)
        oponentHP = random.randint(round(oponentMaxHP*3/4), oponentMaxHP)
        # przeciwnika można by wygenerować jako oddzielna instancja klasy Gra ale nie uważam, żeby to było konieczne w tym przypadku takiej prostej gry

        while(True):
            if(oponentHP<=0):
                #TODO: Dodanie poziomu, zlota itp
                print("Wygrałeś!")
                break
            elif(self.akthp<=0):
                print("Przegrałeś!")
                quit()

            print(f"Twoje zdrowie: {self.akthp}/{self.maxhp}\nZdrowie przeciwnika {oponentHP}/{oponentMaxHP}")
            ruch = input("""1. zaatakuj\n2. użyj mikstury""")
            if(ruch=="1"):
                oponentHP-=self.obrazenia
                print(f"Uderzasz za {self.obrazenia}")
            elif(ruch=="2"):
                if ("healthPotion" in self.napoje):
                    self.akthp = self.maxhp
                    self.napoje.pop("healthPotion")

            oponentDamage = 10 * handicap*(random.randint(8,12)/10)
            self.akthp -= round(oponentDamage)
            print(f"Przeciwnika uderza za {oponentDamage}")
            print("-------------------------------------------------------------\n\n")

    def gainXP(self,xp):
        self.exp+=xp
        if(self.exp>=self.expDoNastepnegoPoziomu):
            self.levelUp()

    def levelUp(self):
        oldMaxhp = self.maxhp
        oldObrazenia = self.obrazenia
        self.poziom+=1
        self.maxhp*=1.5
        self.obrazenia*=1.5
        self.exp = 0
        self.expDoNastepnegoPoziomu*=1.5
        self.zloto += 50 * self.poziom
        print(f"Uzyskałeś poziom {self.poziom}!!!")
        print(f"Obrażenia {oldObrazenia} -> {self.obrazenia}")
        print(f"Zdrowie {oldMaxhp} -> {self.maxhp}")
        print(f"Dostajesz {50 * self.poziom} złota")

    def printInfo(self):
        print(f"Zdrowie: {self.akthp}/{self.maxhp}")
        print(f"Złoto: {self.zloto}")
        print(f"Doświadczenie: {self.exp}/{self.expDoNastepnegoPoziomu}(Poziom {self.poziom})")
        print(f"Obrażenia: {self.obrazenia}")

    def start(self):
        while True:
            ruch = int(input(""" ----------------------------------------------------------------------- \n\n
1. prześpij się w tawernie
2. kup miksturę lecznicza (5 zlota)
3. walka z przeciwnikiem prostym
4. walka z przeciwnikiem trudnym    
5. walka z przeciwnikiem finalowym
6. Wyświetl informacje
Wpisz cyfrę: """))
            print(ruch)
            if(ruch==1):
                self.sleep()
            elif(ruch==2):
                self.buyHealthPotion()
            elif(ruch==3):
                self.startFight(1)
            elif(ruch==4):
                self.startFight(2)
            elif(ruch==5):
                self.startFight(3)
            elif (ruch == 6):
                self.printInfo()


gra = Gra(100,100,0,1,0,[])
gra.start()