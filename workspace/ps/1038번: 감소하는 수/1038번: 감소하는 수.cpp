import sys
from itertools import *
M=[9,8,7,6,5,4,3,2,1,0]
a=[]
for d in range(1,11):
 c=sorted(combinations(M,d))
 for i in c:
  a.append(i)
n=int(input())
if n>len(a)-1:
 print(-1)
else:
 for i in a[n]:
  print(i,end='')