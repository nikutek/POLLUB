import random

def babelkowe(arr):
    for i in range(1, len(arr)):
        for j in range(len(arr)-i):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]

    print(arr)

arr = []

for i in range(10):
    arr.append(random.randint(1,100))


babelkowe(arr)