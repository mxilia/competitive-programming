operation=input()
num=int(input())
length=None
terminate = False
l=[]
for i in range(num):
    s=input()
    s=s.strip()
    l.append(s)
    if length!=len(s):
        if(length==None): length=len(s)
        else: terminate = True
if(terminate):
    print("Invalid size")
    exit(0)
if operation=="90":
    n,m=len(l),len(l[0])
    for j in range(m):
        cs=''
        for i in range(n-1,-1,-1): cs+=l[i][j]
        print(cs)
            
elif operation=="180":
    l.reverse()
    for i in range(len(l)): 
        l[i]=list(l[i])
        l[i].reverse()
        l[i]=''.join(l[i])
    for e in l: print(e)
else:
    for i in range(len(l)): 
        l[i]=list(l[i])
        l[i].reverse()
        l[i]=''.join(l[i])
    for e in l: print(e)
