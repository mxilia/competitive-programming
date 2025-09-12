#
# 04_Loop_02: 04_Bisection_Log10 
#

a = float(input())
L = 0
R = float(a)
mid = (L+R)/2
while abs(a-10**mid)>10**(-10):
    if 10**mid>a: R = mid
    else: L = mid
    mid = (L+R)/2
print(round(mid, 6))