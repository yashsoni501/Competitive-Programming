a=[]
b=[4, 8, 15, 16, 23, 42]

print("? 1 2")
a.append(int(input()))
print("? 2 3")
a.append(int(input()))
print("? 3 4")
a.append(int(input()))
print("? 4 5")
a.append(int(input()))

def check(x):
    boo=1
    for i in range(4):
        if x[i]*x[i+1]!=a[i]:
            boo=0
            break
    if boo:
        print("! "+ str(x[0])+" "+str(x[1])+" "+str(x[2])+" "+str(x[3])+" "+str(x[4])+" "+str(x[5]))
        

def recur(ar,l):
    if len(l)==6:
        check(l)
    else:
        for i in range(len(ar)):
            x=ar[:]
            x.remove(ar[i])
            lt=l[:]
            lt.append(ar[i])
            recur(x,lt)

recur(b,[])