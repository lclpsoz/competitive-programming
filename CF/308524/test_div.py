def div(a, b, n):
	s = "";
	while (a < b):
		a *= 10;
	while a and len(s) < n:
		if (a < b):
			a *= 10;
			while a < b and len(s) < n:
				a *= 10;
				s += '0';
		if len(s) < n:
			s += str(a / b);
		a %= b;
	while len(s) < n:
		s += '0';
	
	return s;

for i in range(1, 100):
	for j in range(200, 300):
		print("i: {} j: {}. R = {} {}".format(i, j, i / j, div(i, j, 20)))
		print("")