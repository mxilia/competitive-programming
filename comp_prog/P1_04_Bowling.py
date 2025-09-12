#
# P1_04_Bowling: Part-I-Bowling 
#

scores = [0]
extra_scores = [0]
each_scores = [0]
end = [0]
s = input().strip()
idx = int(input())
sz = len(s)
i = 0
frame = 0
while i<sz:
    score = 0
    frame += 1
    cnt = 0
    x_en = False
    s_en = False
    while i<sz:
        if(cnt==2 and frame < 10): break
        if(s[i]=='X'):
            x_en = True
            score += 10
            each_scores.append(10)
            if(frame < 10):
                i+=1
                break
        elif(s[i]=='/'):
            s_en = True
            score += (10-int(s[i-1]))
            each_scores.append(10-int(s[i-1]))
            if(frame < 10):
                i+=1
                break
        else:
            score += int(s[i])
            each_scores.append(int(s[i]))
        i+=1
        cnt+=1
    if(x_en): extra_scores.append(2)
    elif(s_en): extra_scores.append(1)
    else: extra_scores.append(0)
    end.append(i)
    scores.append(score)
sum_score = 0
for i in range(1, 11):
    extra = 0
    for j in range(1, extra_scores[i]+1):
        if(end[i]+j>=len(each_scores)): break
        extra+=each_scores[end[i]+j]
    scores[i]+=extra
    sum_score+=scores[i]
if(idx>=1 and idx<=10): print(scores[idx])
else: print(sum_score)
