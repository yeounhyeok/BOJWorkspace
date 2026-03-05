from collections import Counter
n = int(input())
arr=[]
for i in range(n):
    arr.append(int(input()))
arr.sort()
c = Counter(arr).most_common()

print(f"{round(sum(arr)/len(arr))}\n{arr[(n-1)//2]}\n{c[1 if len(c)!=1 and c[0][1]==c[1][1]  else 0][0]}\n{max(arr)-min(arr)}")