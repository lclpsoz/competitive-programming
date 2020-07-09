from math import gcd

n = int(input())

mp = 10100*[0]


line = input().split (' ')
for v in line:
    v = int(v)
    mp[v] += 1
	
x = 1
y = 1

for i in range (10100):
	if (mp[i] > 1):
		x = (x*i)//gcd (x, i)
		y = (y*i)//gcd (y, i)
	elif (mp[i] > 0):
		x = (x*i)//gcd (x, i)
		
print (str (x) + ' ' + str (y))
