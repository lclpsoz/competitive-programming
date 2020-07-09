from random import choice

a = ['R', 'N', 'E']
b = ['A', 'B', 'C']

print ("1 1 1 1000")
for i in range (10000):
	print (choice (a), end="")
print ("")
for i in range (10000):
	print (choice (b), end="")
	
print ("")
