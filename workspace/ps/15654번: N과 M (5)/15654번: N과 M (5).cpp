from itertools import *
n, m = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()
p=permutations(arr, m)
for i in list(p):
    for j in i:
        print(j, '', end='')
    print()