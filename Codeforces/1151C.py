import math

mod=1000000007
def summer(a):
    if a==0:
        return 0
    terms=int(math.log(a,2))
    odd=0
    even=0
    ein=1
    for i in range(0,terms+1,2):
        even=(ein+even)%mod
        ein=(ein*4)%mod
    
    oin=2;
    for i in range(1,terms+1,2):
        odd=(odd+oin)%mod
        oin=(oin*4)%mod
    if(terms%2==0):
        even=(even+a-int(pow(2,terms+1))+1)%mod
    else:
        odd=(odd+a-int(pow(2,terms+1))+1)%mod
        
    ans=(even*even)%mod
    ans=(ans+odd*(odd+1))%mod
    return ans

inp=input()
l=int(inp.split(" ")[0])
r=int(inp.split(" ")[1])
ans=int((summer(r)-summer(l-1))%mod)
print(ans)