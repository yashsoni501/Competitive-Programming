def solution(l):
    
    adj = {}
    for i in range(len(l)):
        adj[i] = []
    for i in range(len(l)):
        for j in range(i+1,len(l)):
            if l[j]%l[i] == 0:
                adj[i].append(j)
        
    print(adj)
    cnt=0
    for i in range(len(l)):
        for j in adj[i]:
            cnt+=len(adj[j])
            
    return cnt