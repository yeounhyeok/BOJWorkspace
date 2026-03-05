import sys
print = sys.stdout.write

arr=list()
def move(frm, to):
    arr.append([frm, to])

def hanoi(n, start, to, via):
    if n==1:
        move(start, to)
    else:
        hanoi(n-1, start, via, to)
        move(start, to)
        hanoi(n-1, via, to, start)

N = int(input())
print(f"{2**N-1}\n")
if N>20:
    quit()
hanoi(N, 1, 3, 2)
for i in arr:
    print(f"{i[0]} {i[1]}\n")

