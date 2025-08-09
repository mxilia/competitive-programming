def convex_polygon_area(p):
    a,b=p[len(p)-1][0]*p[0][1],p[0][0]*p[len(p)-1][1]
    for i in range(len(p)):
        if(i<len(p)-1): a+=p[i][0]*p[i+1][1]
        if(i>0): b+=p[i][0]*p[i-1][1]
    return abs((a-b)/2)

def is_heterogram(s:str):
    s=list(s.lower())
    d = {}
    for e in s:
        if e.isalpha():
            if(d.get(e)!=None): return False
            d[e]=1
    return True

def replace_ignorecase(s:str, a:str, b:str):
    ans=[]
    c=''
    for i in range(len(s)):
       c+=s[i]
       if(len(c)==len(a)):
           if(c.lower()==a.lower()): 
               ans.append(b)
               c=''
           else:
               ans.append(c[0])
               if(len(c)>0): c=c[1:len(c)]
               else: c=''
    ans.append(c)
    return ''.join(ans)

def top3(d:dict):
    l=[]
    for key, val in d.items(): l.append((val,key))
    l.sort(key=lambda x:(x[0],500-ord(x[1])),reverse=True)
    return [l[i][1] for i in range(min(3,len(l)))]

for k in range(2):
    exec(input().strip())
    