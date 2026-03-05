from itertools import *
n, m = map(int, input().split())
arr = list(map(int, input().split()))
p=list(permutations(arr, m))
for i in sorted(list(set(p))):
    for j in i:
        print(j, '', end='')
    print()