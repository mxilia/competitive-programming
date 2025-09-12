#
# 02_StrList_07: 02_Decryption 
#

code = input()
first = code[3::7]
second = code[7::5]
res = str(int(first)+int(second)+10000)[::-1]
res = res[1:4][::-1]
char_code = chr(ord('A')+(int(res[0])+int(res[1])+int(res[2]))%10)
print(res+char_code)