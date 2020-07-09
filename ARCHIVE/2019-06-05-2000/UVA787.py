import sys

inp = []
for line in sys.stdin:
	line = line.split (' ')
	for x in line:
		inp.append (int (x))
		
#print (inp)

lsts = [[]]
for x in inp:
	x = int (x)
	if (x == -999999):
		lsts.append ([])
	else:
		
		lsts[-1].append (x)

#print (lsts)


for lst in lsts:
	if (len (lst) == 0):
		continue
	#print ("lst: " + str (lst))
	now = [[]]
	haveZero = False
	for x in lst:
		if (x == 0):
			haveZero = True
			if (len (now[-1]) > 0):
				now.append ([])
		else:
			now[-1].append (x)
	
	if (len (now[-1]) == 0):
		del (now[-1])
	if (haveZero):
		ans = 0
	else:
		ans = ' '
	#print (ans)
	for seq in now:
		val = 1
		for x in seq:
			val *= x
			
		if (ans == ' '):
			ans = val
		else:
			ans = max (ans, val)
		#print ("ans: " + str (ans))
		ax = val
		for i in range (len (seq) - 1):
			ax //= seq[i]
			ans = max (ans, ax)
		
		ax = val
		i = len (seq) - 1
		while (i > 0):
			ax //= seq[i]
			ans = max (ans, ax)
			i -= 1
		#print (seq)
		#print (ans)

	print (ans)
