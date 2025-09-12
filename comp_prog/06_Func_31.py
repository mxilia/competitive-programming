#
# 06_Func_31: 06_Refactor 
#

# -*- coding: utf-8 -*-

mname = ["Jan", "Feb","Mar","Apr",
         "May","Jun","Jul","Aug",
         "Sep","Oct","Nov","Dec"]

def read_date():
    date = input().split()
    d = int(date[0])
    m = mname.index(date[1][:3]) + 1
    y = int(date[2])
    return [d, m, y]

# หาราศี
def zodiac(d1, m1):
    z1 = ''
    if d1 >= 22 and m1==3 or d1 <=21 and m1==4 : z1 = "Aries"
    elif d1 >= 22 and m1==4 or d1 <=21 and m1==5 : z1 = "Taurus"
    elif d1 >= 22 and m1==5 or d1 <=21 and m1==6 : z1 = "Gemini"
    elif d1 >= 22 and m1==6 or d1 <=21 and m1==7 : z1 = "Cancer"
    elif d1 >= 22 and m1==7 or d1 <=21 and m1==8 : z1 = "Leo"
    elif d1 >= 22 and m1==8 or d1 <=21 and m1==9 : z1 = "Virgo"
    elif d1 >= 22 and m1==9 or d1 <=21 and m1==10 : z1 = "Libra"
    elif d1 >= 22 and m1==10 or d1 <=21 and m1==11 : z1 = "Scorpio"
    elif d1 >= 22 and m1==11 or d1 <=21 and m1==12 : z1 = "Sagittarius"
    elif d1 >= 22 and m1==12 or d1 <=20 and m1==1 : z1 = "Capricorn"
    elif d1 >= 21 and m1==1 or d1 <=20 and m1==2 : z1 = "Aquarius"
    elif d1 >= 21 and m1==2 or d1 <=21 and m1==3 : z1 = "Pisces"
    return z1

def days_in_feb(y):
    days = 28
    if y % 400 == 0 or y % 100 != 0 and y % 4 == 0 :
        days = 29
    return days
 
def days_in_month(m, y):
    days_in_m = 31
    if m==4 or m==6 or m==9 or m==11 :
        days_in_m = 30
    elif m==2 :
        days_in_m = days_in_feb(y)
    return days_in_m

# เริ่มหาจำนวนวันตั้งแต่ d1,m1,y1 ถึง d2,m2,y2 วิธีที่เขียนอาจผิดพลาดเล็กน้อย ไม่ต้องแก้นะ
def days_in_between(d1, m1, y1, d2, m2, y2):
    days = 0
    if m1 < 12 : days += 31
    if m1 < 11 : days += 30
    if m1 < 10 : days += 31
    if m1 < 9 : days += 30
    if m1 < 8 : days += 31
    if m1 < 7 : days += 31
    if m1 < 6 : days += 30
    if m1 < 5 : days += 31
    if m1 < 4 : days += 30
    if m1 < 3 : days += 31
    if m1 < 2 : days += days_in_feb(y1)
    if m2 > 1 : days += 31
    if m2 > 2 : days += days_in_feb(y2)
    if m2 > 3 : days += 31
    if m2 > 4 : days += 30
    if m2 > 5 : days += 31
    if m2 > 6 : days += 30
    if m2 > 7 : days += 31
    if m2 > 8 : days += 31
    if m2 > 9 : days += 30
    if m2 > 10 : days += 31
    if m2 > 11 : days += 30
    days += (days_in_month(m1, y1) - d1 + 1) + int((y2 - y1 - 1)*365.25) + (d2 - 1)
    return days

def main():
     d1,m1,y1 = read_date()
     d2,m2,y2 = read_date()
     print(zodiac(d1,m1)+" "+zodiac(d2,m2))
     print(days_in_between(d1,m1,y1,d2,m2,y2))
exec(input().strip())
