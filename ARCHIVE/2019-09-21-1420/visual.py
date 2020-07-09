from PIL import Image

RES = 30
numOfImages = 20

base = []
for i in range (numOfImages):
    base.append ([])
it = 0
while (True):
    now = input().split (',')
    if (len (now[0]) > 3):
        break
    if (int (now[0]) != it):
        it += 1
    
    print (it)
    base[it].append (float (now[1]))

delta = []
miniL = []
for it in range (numOfImages):
    mini = 10000000000000
    maxi = -1000000000000
    for i in base[it]:
        i = float (i)
        if (i < mini):
            mini = i
        if (i > maxi):
            maxi = i
    print (maxi, mini)
    delta.append ((maxi - mini) / 765)
    miniL.append (mini)

im = Image.new('RGB', (RES, numOfImages * RES))

data = []
for it in range (numOfImages):
    for i in base[it]:
        i = float (i)
        i = round ((i - miniL[it]) / delta[it])
        r = min (255, i)
        g = max (0, i-255)
        b = max (0, i-510)
        data.append ((r, g, b))

im.putdata(data)
im.save('test_2.png')
