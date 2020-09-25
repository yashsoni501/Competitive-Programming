t=int((input()))
for i in range(t):
    boo=False
    string=str(input())
    ls=string.split(" ")
    for j in ls:
        if j=="not":
            boo=True
    if boo:
        print("Real Fancy")
    else:
        print("regularly fancy")