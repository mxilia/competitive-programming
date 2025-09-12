#
# 03_If_09: 03_Biorhythm 
#
import math

def sin_format(d):
    return "{:.2f}".format(math.sin(2*math.pi*tdays/d))

def leap_year(year):
    year-=543
    if(year%4==0 and year%100): return True
    if(year%400==0): return True
    return False

def to_end(day, month, year):
    temp = day
    day = 0
    if(month<=1): day+=31
    if(month<=2):
        if(leap_year(year)): day+=29
        else: day+=28
    if(month<=3): day+=31 
    if(month<=4): day+=30
    if(month<=5): day+=31
    if(month<=6): day+=30
    if(month<=7): day+=31
    if(month<=8): day+=31
    if(month<=9): day+=30
    if(month<=10): day+=31
    if(month<=11): day+=30
    if(month<=12): day+=31
    return day-temp+1

def from_start(day, month, year):
    temp = day
    day = 0
    if(month>1): day+=31
    if(month>2):
        if(leap_year(year)): day+=29
        else: day+=28
    if(month>3): day+=31 
    if(month>4): day+=30
    if(month>5): day+=31
    if(month>6): day+=30
    if(month>7): day+=31
    if(month>8): day+=31
    if(month>9): day+=30
    if(month>10): day+=31
    if(month>11): day+=30
    if(month>12): day+=31
    return day+temp-1

bd, bm, by, d, m, y = [int(e) for e in input().split()]
y_btw = (y-by-1)*365
bdays = to_end(bd, bm, by)
cdays = from_start(d, m, y)
tdays = y_btw+bdays+cdays
# print(bdays, y_btw, cdays)
print(tdays, sin_format(23), sin_format(28), sin_format(33))


