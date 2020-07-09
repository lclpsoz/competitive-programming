from PIL import Image
mini = 10000000
maxi = -10000000

pts = []
n = int (input())
mat = []
for i in range (1001):
    mat.append ([0]*1001)
    
maxi = 0
for i in range (n):
    x, y = input().split(' ')
    x = round (float (x) / 20) + 500
    y = round (float (y) / 20) + 500
    #pts.append ([int (x) + 500, int (y) + 500])
    mat[x][y]+=1
    maxi = max (mat[x][y], maxi)

print (mat[1])
#print (pts)

print ("maxi: " + str (maxi))
delta = 255/maxi
#print (mat)

im= Image.new('RGB', (1001, 1001))

data = []
for lin in mat:
    print (".", end="")
    for cell in lin:
        data.append ((int(round (cell*delta)), 0, 0))
print ("")

im.putdata(data)
im.save('graph.png')
