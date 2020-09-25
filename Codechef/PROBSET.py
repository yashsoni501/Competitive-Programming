t=int(input());
for i in range(t):
    case=2 #2=fine 0=invalid 1=weak
    tmp=input();
    
    li=tmp.split(" ");
    n=int(li[0])
    m=int(li[1])
    for j in range(n):
        s=input();
        l=s.split(" ")
        print(l)
        if l[0]=="correct" and l[1]!='1'*m:
            case=0
        elif l[0]=="wrong" and l[1]=='1'*m:
            case=1
    if case==0:
        print("INVALID")
    elif case==1:
        print("WEAK")
    else:
        print("FINE")