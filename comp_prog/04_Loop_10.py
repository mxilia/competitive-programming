#
# 04_Loop_10: 04_Bisection_Log10_2 
#

a = float(input())
L, R = 0, 0
temp = float(a)
while temp:
    temp//=10
    R+=1
mid = (L+R)/2
while abs(10**mid-a)>10**-10*max(10**mid, a):
    if 10**mid>a: R = mid
    else: L = mid
    mid = (L+R)/2
print(round(mid, 6))
