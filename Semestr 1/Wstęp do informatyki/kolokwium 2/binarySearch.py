import random


def search(arr, target):
    left = 0
    right = len(arr)
    mid = (left + right) // 2
    while mid != target:
        if (target > mid):
            left = mid
        elif ( target < mid):
            right = mid
        mid = (left+right)//2
    print(mid)

arr = list(range(100))
target = random.randint(1,100)

search(arr, target)
