def proc(x,n,m):
    p=0
    for i in range(len(x)):
        p += int(x[-i-1])*(n**i)
        if p>m:
            return p
    return p

def bs(l,h):
    mid = (h+l)//2
    while h-l>1:
        if proc(x,mid,m)<=m:
            l=mid
        else:
            h=mid
        mid = (h+l)//2
    return l

x = str(input())
m = int(input())

if(len(x) == 1):
    if(int(x)<=m):
        print(1)
        exit()
    else:
        print(0)
        exit()

d = max(x)
n = int(d)+1

cnt=0
t = proc(x,n,m)

print(bs(int(d),m+2)-int(d))