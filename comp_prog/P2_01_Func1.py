def is_odd(n):
    return bool(n%2)

def has_odds(x):
    for e in x:
        if is_odd(e):
            return True
    return False

def all_odds(x):
    for e in x:
        if not is_odd(e):
            return False
    return True

def no_odds(x):
    return not has_odds(x)

def get_odds(x):
    t=[]
    for e in x:
        if is_odd(e):
            t.append(e)
    return t

def zip_odds(a_,b_):
    a=get_odds(a_)
    b=get_odds(b_)
    res=[]
    adx,bdx=0,0
    while adx<len(a) and bdx<len(b):
        res.append(a[adx])
        adx+=1
        res.append(b[bdx])
        bdx+=1
    while adx<len(a):
        res.append(a[adx])
        adx+=1
    while bdx<len(b):
        res.append(b[bdx])
        bdx+=1
    return res

exec(input().strip())