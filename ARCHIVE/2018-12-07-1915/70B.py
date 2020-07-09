n = int(input())
text = input()

text = text.replace("?", ".").replace("!", ".").split(".")

ans = True
qnt = 0
acu = n+1
for i in range (len(text)):
    if (len (text[i]) == 0):
        continue
    #text[i] = text[i].strip()
    #print ("|" + text[i])
    if (len (text[i]) > n):
        ans = False
        break
    acu += len (text[i]) + 1
    if (acu > n):
        acu = len (text[i])+1
        if (text[i][0] == ' '):
            acu -= 1
        qnt += 1        
        
if (ans == False):
    print ("Impossible")
else:
    print (qnt)
