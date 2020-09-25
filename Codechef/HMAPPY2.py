def gcd(a,b):
    if(a==0):
        return b
    else:
        return gcd(b%a,a)
    
def lcm(a,b):
    return a*b/gcd(a,b)

t=int(input())

for i in range(t):
    string=input()
    lst=string.split(" ")
    n=int(lst[0])
    a=int(lst[1])
    b=int(lst[2])
    k=int(lst[3])
    num=n/a+n/b-2*n/lcm(a,b)
    if num<k:
        print("Lose")
    else:
        print("Win")