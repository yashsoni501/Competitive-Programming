n = int(input())
p = list(map(float, input().split()))
q=[]
q.append([1])
for i in range(n):
    q[0].append(0)
prod = 1.0
for i in range(1,n+1):
    prod*=p[i-1]
    q.append([prod])

for i in range(1,n+1):
    for j in range(1,n+1):
        try:
            q[i].append(p[i-1]*q[i-1][j] + (1-p[i-1])*q[i-1][j-1])
        except:
            print(i)
            print(j)
        #print(q)
ans = 0.0
for i in range(0,(n-1)//2+1):
    ans+=q[n][i]
print(ans)
