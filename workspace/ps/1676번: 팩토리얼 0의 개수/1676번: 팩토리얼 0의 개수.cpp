n=int(input())
for i in range(1, n):
    n*=i
n=str(n)
cnt=0
for i in range(n.__len__()-1, 0, -1):
    if n[i]=='0':
        cnt+=1
    else:
        break
print(cnt)