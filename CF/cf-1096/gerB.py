# print (chr (ord('a') + 1))

lst = []

def func (n, p):
	if (p == n):
		var = lst[0]
		test = False
		for i in lst:
			if (i != var):
				test = True
		if (test == False):
			return;
		print (n)
		for i in lst:
			print (i, end="")
		print("")
	else:
		for j in range (p+1):
			lst.append (chr(ord('a')+j))
			func (n, p+1)
			lst.pop()

for i in range (8, 9):
	func (i, 0)