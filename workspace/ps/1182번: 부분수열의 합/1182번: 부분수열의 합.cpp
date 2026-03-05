from itertools import *
cnt=0;
n, m = map(int, input().split())
v=list(map(int, input().split()))
v.sort()
for i in range(1, n+1):
    c = list(combinations(v, i))
    for comb in c:
        if sum(comb) == m:
            cnt+=1
print(cnt)