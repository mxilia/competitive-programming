convert = { "E" : 1, "Q" : 3, "N" : 7, "F" : 14 }
correct, ans = [], []
mtd = [0,31,28,31,30,31,30,31,31,30,31,30,31]
starting_year = 2558

def print_error(order, error_msg):
    print("Error: "+order+" --> "+error_msg)
    return

def leap_year(year):
    if year%400==0 or (year%4==0 and year%100!=0): return True
    return False

def order_delivered_date(order):
    nday = (order[2]+convert[order[1]])%(mtd[order[3]]+1)+((order[2]+convert[order[1]])>mtd[order[3]])
    nmonth = (order[3]+(order[2]+convert[order[1]]>mtd[order[3]]))%13+((order[3]+(order[2]+convert[order[1]]>mtd[order[3]]))%13==0)
    nyear = order[4]+((order[3]+(order[2]+convert[order[1]]>mtd[order[3]]))>12)
    return [order[0]+": delivered on "+str(nday)+"/"+str(nmonth)+"/"+str(nyear), nyear, nmonth, nday, int(order[0])]

while True:
    order = input()
    if(order=="END"): break
    num, ot, day, month, year = order.split(" ")
    if int(year)<starting_year:
        print_error(order, "Invalid year")
    elif int(month)<1 or int(month)>12:
        print_error(order, "Invalid month")
    elif int(day)<1 or int(day)>(mtd[int(month)]+(month=="2" and leap_year(int(year)-543))):
        print_error(order, "Invalid date")
    elif convert.get(ot)==None:
        print_error(order, "Invalid delivery type")
    else: correct.append([num, ot, int(day), int(month), int(year)])
for e in correct: ans.append(order_delivered_date(e))
ans.sort(key=lambda x: (x[1], x[2], x[3], x[4]))
for e in ans: print(e[0])