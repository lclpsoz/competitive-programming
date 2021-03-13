import random

f = open("in", "w")

n = 700

f.write(str(n) + '\n')
a = []
while len(a) != n:
	a.append(random.randint(-3000, 3000))
	a = list(dict.fromkeys(a))
for i in range(len(a)):
	f.write(str(a[i]) + " ")
f.write('\n')

f.write(str(n) + '\n')
a = []
while len(a) != n:
	a.append(random.randint(-3000, 3000))
	a = list(dict.fromkeys(a))
for i in range(len(a)):
	f.write(str(a[i]) + " ")
f.write('\n')

f.write(str(n) + '\n')
a = []
while len(a) != n:
	a.append(random.randint(-3000, 3000))
	a = list(dict.fromkeys(a))
for i in range(len(a)):
	f.write(str(a[i]) + " ")
f.write('\n')

f.close()