from fractions import Fraction as frac
from random import seed
from random import random
from random import randint

def gcd(a, b):
    if a==0:
        return b
    return gcd(b%a, a)

def lcm(a, b):
    return a*b//gcd(a,b)

def inverse(A):
    row = len(A)
    
    M = []
    for i in range(row):
        M.append([])
        for j in range(row):
            M[i].append(A[i][j])
        for j in range(row):
            if i==j:
                M[i].append(frac(1,1))
            else:
                M[i].append(frac(0,1))
                                
    for i in range(row-1,0,-1):
        if M[i-1][0] < M[i][0]:
            for j in range(2*row):
                temp = M[i][j]
                M[i][j] = M[i-1][j]
                M[i-1][j] = temp
                
    for i in range(row):
        for j in range(row):
            if j != i:
                temp = M[j][i] / M[i][i]
                for k in range(2*row):
                    M[j][k] -= M[i][k] * temp
           
    for i in range(row):
        temp = M[i][i]
        for j in range(2*row):
            M[i][j] = M[i][j] / temp
                        
    I = []
    for i in range(row):
        I.append([])
        for j in range(row):
            I[i].append(M[i][j+row])
            
    return I

def multiply(A,B):
    
    C = []

    for i in range(len(A)):
        C.append([])
        for j in range(len(B[0])):
            C[i].append(frac(0,1))
            for k in range(len(B)):
                C[i][j] += A[i][k] * B[k][j]

    return C

def solution1(m): 
    
    A = []
    T = []
    l = []
    Aig = []
    
    for i in range(len(m)):
        l.append(sum(m[i]))
        if sum(m[i]) == 0:
            A.append(i)
            Aig.append(i)
        elif m[i].count(0) == len(m)-1:
            if m[i][i] == 0:
                T.append(i)
            else:
                Aig.append(i)
        else:
            T.append(i)
            
    #print(A)
    #print(Aig)
    #print(T)
    
    if 0 in Aig:
        ans = [1]
        for i in range(len(A)-1):
            ans.append(0)
        ans.append(1)
        return ans
        
    
    Q = []
    for i in range(len(T)):
        Q.append([])
        for j in range(len(T)):
            Q[i].append(frac(m[T[i]][T[j]], l[T[i]]))
    
    R = []
    for i in range(len(T)):
        R.append([])
        for j in range(len(A)):
            R[i].append(frac(m[T[i]][A[j]], l[T[i]]))

    print(Q)
    print(R)            
    
    IQ = []
    for i in range(len(Q)):
        IQ.append([])
        for j in range(len(Q)):
            if i==j:
                IQ[i].append(frac(1,1))
            else:
                IQ[i].append(frac(0,1))
                
    for i in range(len(Q)):
        for j in range(len(Q)):
            IQ[i][j] = IQ[i][j] - Q[i][j]
        
    #print(IQ)
    
    for i in range(10):
        print(IQ[i][i])
    
    IQinv = inverse(IQ)
    
    #print(IQinv)
    
    X = multiply(IQinv, R)
    
    #print(X)
    
    ans = []
    den = 1
    for i in range(len(X[0])):
        den = lcm(den, X[0][i].denominator)
        
    for i in range(len(X[0])):
        ans.append(X[0][i].numerator*(den//X[0][i].denominator))
        
    ans.append(den)
    
    return ans

def solution2(m): 
    for i in range(len(m)):
        if sum(m[i]) == 0:
            m[i][i] = 1
    
    for i in range(len(m)):
        s = sum(m[i])
        for j in range(len(m[0])):
            m[i][j]/=s
    
    p = []
    p.append([1])
    for i in range(len(m)-1):
        p[0].append(0)
    for i in range(1000):
        p = multiply(p,m)
    
    ans = []
    for i in range(len(p)):
        if p[i]<1e-20:
            ans.append(p[i])
    
    return ans

seed(1)
m = []
for i in range(7):
    m.append([])
    for j in range(10):
        tmp = random()
        if(tmp>0.5):
            m[i].append(0)
        else:
            m[i].append(randint(0,100)%10+1)

for i in range(3):            
    m.append([0]*10)
    
print(m)
print(solution1(m))
print(solution2(m))
