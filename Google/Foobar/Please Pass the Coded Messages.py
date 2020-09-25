def solution(l):
    
    s = sum(l)
    cnt = [0]*3
    x = [0]*10
    for i in l:
        x[i]+=1
        cnt[i%3]+=1
    
    if s%3==1:
        if cnt[1]>0:
            cnt[1]-=1
        elif cnt[2]>1:
            cnt[2]-=2
        else:
            return 0
    elif s%3==2:
        if cnt[2]>0:
            cnt[2]-=1
        elif cnt[1]>1:
            cnt[1]-=2
        else:
            return 0
    
    n = ""
    for i in range(9,-1,-1):
        n+=str(i)*min(cnt[i%3],x[i])
        cnt[i%3]-=min(cnt[i%3],x[i])
        
    if len(n)==0:
        return 0
    return int(n)