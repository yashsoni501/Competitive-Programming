def solution(l,t):
    for i in range(len(l)):
        som = 0
        for j in range(i,len(l)):
            som+=l[j]
            if som==t:
                return [i,j]
            elif som>t:
                break
    return [-1,-1]