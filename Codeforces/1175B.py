n=int(input())
b=True
cnt=0
ad=1
lst=[]
tm=n
while tm:
    tm-=1

    inp=str(input())
    if inp == 'end':
        ad/=lst[-1]
        lst.pop(-1)
    elif inp.split(" ")[0] == 'for':
        tmp=int(inp.split(" ")[1])
        ad*=tmp
        lst.append(tmp)
    else:
        cnt+=ad
        
    if cnt>4294967295:
        print("OVERFLOW!!!")
        b=False
        while tm:
            tm-=1
            inp=str(input())
if b:
    print(int(cnt))