#
# 02_StrList_08: 02_Decimal2Fraction 
#
import math

s = input().split(',')
shift_nine = len(s[2])
shift_zero = len(s[1])
total_shift = shift_zero + shift_nine
temp = (s[0]+s[1]+s[2]*(total_shift//len(s[2]))+s[2][0:total_shift%len(s[2])])
many_x = temp[0:len(s[0])-1+shift_nine+shift_zero+1]
one_x = temp[0:len(s[0])-1+shift_zero+1]
numerator = int(many_x)-int(one_x)
denominator = int(str("9"*shift_nine+"0"*shift_zero))
divis = math.gcd(numerator, denominator)
print(str(numerator//divis)+" / "+str(denominator//divis))
# 123,456,789