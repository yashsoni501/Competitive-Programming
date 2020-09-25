def gcd(a,b):
    if b==0:
        return a
    else:
        return gcd(b,a%b)

def solve(x,y):    
    if x==0:
        return -1
    return y//x + solve(y%x,x)

def solution(a,b):
    a = int(a)
    b = int(b)
    g = gcd(a,b)
    if g!=1:
        return "impossible"
    s = solve(min(a,b),max(a,b))
    return str(s)