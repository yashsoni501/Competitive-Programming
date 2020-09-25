def sieve(n):
    s = ""
    prime = [1]*n;
    for i in range(2,n):
        if prime[i]:
            for x in range(i*i,n,i):
                prime[x]=0
    for i in range(2,n):
        if prime[i]:
            s+=str(i)
    return s

def solution(i):
    s = sieve(100000)
    return s[i:i+5]