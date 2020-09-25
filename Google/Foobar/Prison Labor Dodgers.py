def solution(x,y):
    if len(x)>len(y):
        t = x
        x = y
        y = t
    
    x.sort()
    y.sort()
    
    for i in range(len(x)):
        if x[i]!=y[i]:
            return y[i]
    return y[-1]