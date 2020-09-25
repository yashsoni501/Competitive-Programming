def multiply(A,B):
    
    C = []

    for i in range(len(A)):
        C.append([])
        for j in range(len(B[0])):
            C[i].append(0)
            for k in range(len(B)):
                C[i][j] += A[i][k] * B[k][j]

    return C

def solution(m): 
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
    print(p)
    for i in range(1000):
        p = multiply(p,m)
    
    ans = []
    for i in range(len(p)):
        if p[i]<1e-20:
            ans.append(p[i])
    
    return ans