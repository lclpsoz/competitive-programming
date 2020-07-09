#include <bits/stdc++.h>
using namespace std;

typedef long long int lld;
const lld OPT = 1e11;

vector<lld> vec;
char c;

int rev (int pos)
{
	if (vec.size() == 1 && vec[0] < OPT)
		return 1;
	int estado = 1;
	//printf ("%d %d %lld %lld %lld %lld\n", pos, estado, vec[pos], vec[pos+1], vec[pos+2], 0/2);
	while (estado == 1 && pos+2 < vec.size() && (vec[pos+1] > OPT || vec[pos+2] > OPT)) {
		if (vec[pos] < OPT)
			estado = 0;
		else if (vec[pos+1] > OPT)
			estado = rev (pos+1);
		else if (vec[pos+2] > OPT)
			estado = rev (pos+2);
	}
	if (estado == 1 && pos+2 >= vec.size())
		estado = 0;
	//printf ("%d %d %lld %lld %lld %lld\n", pos, estado, vec[pos], vec[pos+1], vec[pos+2], 0/2);
	if (estado == 1) {
		switch (vec[pos]) {
			case (lld)OPT+1: vec[pos] = vec[pos+2] + vec[pos+1];
						break;
			case (lld)OPT+2: vec[pos] = vec[pos+2] - vec[pos+1];
						break;
			case (lld) OPT+3: vec[pos] = vec[pos+2] * vec[pos+1];
						break;
			case (lld)OPT+4: if (vec[pos+1] == 0)
							estado = 2; //Division by zero.
						else
							vec[pos] = vec[pos+2] / vec[pos+1];
						break;
		}
		vec.erase (vec.begin()+pos+1, vec.begin()+pos+3);
	}
	return estado;
}

int main ()
{
	int estado, num, opr;
	c = getchar ();
	while (c != EOF) {
		num = opr = 0;
		while (c != '\n') {
			while (c == ' ')
				c = getchar();
			if (c != '\n' && c != EOF) {
				if (c == '+')
					vec.push_back (OPT+1);
				else if (c == '-')
					vec.push_back (OPT+2);
				else if (c == '*')
					vec.push_back (OPT+3);
				else if (c == '/')
					vec.push_back (OPT+4);
				else {
					num++; opr--;
					vec.push_back (c-'0');
				}
				opr++;
				c = getchar ();
			}
		}
		estado = rev (0);
		if (estado == 1 && vec.size() > 1)
			estado = 0;
		if (estado == 1)
			printf ("The answer is %lld.\n", vec[0]);
		else if (estado == 2)
			printf ("Division by zero.\n");
		else
			printf ("Invalid expression.\n");
		vec.clear();
		if (c != EOF)
			c = getchar ();
	}
	return 0;
}
