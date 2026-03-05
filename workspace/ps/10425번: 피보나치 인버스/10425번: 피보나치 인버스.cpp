n=int(input())
arr=[]
arr.append(0)
arr.append(1)
for i in range(n):
    x=int(input())
    if x==0:
        print("0")
        continue
    if x==1:
        print("2")
        continue
    
    j=0
    isDone=False
    while arr.__len__()>=j+1:
        if arr[j]==x:
            print(j)
            isDone=True
            break
        j+=1
    if isDone is True:
        continue
    j=arr.__len__()
    while 1:
        arr.append(arr[j-1]+arr[j-2])
        if arr[j]==x:
            print(j)
            isDone=False
            break
        j+=1