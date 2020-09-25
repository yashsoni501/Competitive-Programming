def isValid(x,y,w,h,l,vis):
    return -1<x<w and -1<y<h and l[x][y] == 0 and vis[x][y] == 0

def bfs(l):
    w = len(l)
    h = len(l[0])
    vis = []
    for i in range(w):
        vis.append([])
        for j in range(h):
            vis[i].append(0)

    vis[0][0]=1
    queue = [(0,0,1)]
    while len(queue):
        top = queue.pop(0)
        if top[0] == w-1 and top[1] == h-1:
            return top[2]

        x,y,dep = top
        if isValid(x+1,y,w,h,l,vis):
            queue.append((x+1,y,dep+1))
            vis[x+1][y]=1
        if isValid(x,y+1,w,h,l,vis):
            queue.append((x,y+1,dep+1))
            vis[x][y+1]=1
        if isValid(x-1,y,w,h,l,vis):
            queue.append((x-1,y,dep+1))
            vis[x-1][y]=1
        if isValid(x,y-1,w,h,l,vis):
            queue.append((x,y-1,dep+1))
            vis[x][y-1]=1

    return 1000000000
            
def solution(l):
    if len(l) == 1 and len(l[0]) == 1:
        return 1
    if l[0][0] == 1:
        l[0][0] = 0
        return bfs(l)
    ones = []
    for i in range(len(l)):
        for j in range(len(l[0])):
            if l[i][j] == 1:
                ones.append((i,j))
    mi = bfs(l)
    one = ones[0]
    l[one[0]][one[1]] = 0
    mi = min(mi,bfs(l))
    
    for i in range(1,len(ones)):
        l[ones[i-1][0]][ones[i-1][1]] = 1
        l[ones[i][0]][ones[i][1]] = 0
        mi = min(mi,bfs(l))
        
    return mi
