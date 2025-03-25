
nums = []
for i in range(1,4):
    toAdd = input("Podaj liczbę nr"+str(i)+": ")
    nums.append(int(toAdd))

print("Największa liczba z podanych: "+str(sorted(nums)[-1]))
