n = int (input())

if (n < 3):
	print ("-1")
else:
	x = 10**(n-1)
	x -= x%210 - 210
	print (x)