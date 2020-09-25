mod=1000000007
from math import gcd
def egcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, y, x = egcd(b % a, a)
        return (g, x - (b // a) * y, y)

def modinv(a, m):
    g, x, y = egcd(a, m)
    if g != 1:
        print(3/0)
    else:
        return x % m

t=int(input())

for i in range(t):
    lst=str(input()).split(" ")
    n=int(lst[0])
    k=int(lst[1])
    m=int(lst[2])

    if m%2==0:
        j=m//2
        q=pow(n,j,mod)*(n+k)
        p=q-pow(n-1,j,mod)*(n+k-1)
    else:
        j=(m+1)//2
        
        q=pow(n,j,mod)
        p=q-pow(n-1,j,mod)
        
    #print(p,q)
    g=gcd(p,q)
    p/=g
    q/=g
    
    p=int((p+mod)%mod)
    q=int((q+mod)%mod)
    
    print ((int(p*modinv(q,mod)))%mod)
    