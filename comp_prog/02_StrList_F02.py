#
# 02_StrList_F02: 02_Arabic_Numerals (Function) 
#

ntoc = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]

def number_name(n):
    n=int(n)
    return ntoc[n]

exec(input()) # DON'T remove this line