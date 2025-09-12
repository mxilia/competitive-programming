#
# 04_Loop_20: 04_ZigZag_2 
#
max1, max2 = -10**18, -10**18
min1, min2 = 10**18, 10**18
row = 0

while True:
    s = input().split(' ')
    if(len(s)==1):
        if(s[0]=="Zig-Zag"): print(min1, max1)
        else: print(min2, max2)
        break
    s[0], s[1] = int(s[0]), int(s[1])
    min1 = min(min1, s[row%2])
    max1 = max(max1, s[(row+1)%2])
    min2 = min(min2, s[(row+1)%2])
    max2 = max(max2, s[row%2])
    row+=1