n = int (input())

ans = False
out = []
for i in range (n):
    row = input().split ('|')
    if (ans == False and row[0] == "OO"):
        ans = True
        row[0] = "++"
    if (ans == False and row[1] == "OO"):
        ans = True
        row[1] = "++"
    out.append (row[0] + "|" + row[1])

if (ans == False):
    print ("NO")
else:
    print ("YES")
    for i in out:
        print (i)
        
