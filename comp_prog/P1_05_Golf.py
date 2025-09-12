#
# P1_05_Golf: Part-I-Golf 
#
import math

total_par = 0
total_stroke = 0
total_stroke_fix = 0
for i in range(9):
    a, b, c = [int(e) for e in input().strip().split(" ")]
    total_par += a
    total_stroke += b
    if(c): total_stroke_fix += min(a+2, b)
continue_score = math.floor(0.8*(1.5*total_stroke_fix-total_par))
print(total_stroke)
print(continue_score)
print(total_stroke-continue_score)