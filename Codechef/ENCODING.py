MOD = 1000000007

def combi(a):
    if a==0:
        return 0
    if a%2==0:
        return (((a//2)%MOD)*((a-1)%MOD))%MOD
    else:
        return ((a%MOD)*(((a-1)//2)%MOD))%MOD

def solve(a):
    suum = combi(a)
    
    return suum    
t = int(input())

while t:
    t-=1
    
    (nl,l) = (int(i) for i in str(input()).split(" "))
    (nr,r) = (int(i) for i in str(input()).split(" "))
    
    l-=1
    ans = solve(r)-solve(l)
    print(ans)