#include <bits/stdc++.h>
using namespace std;

typedef long long int lld;
const lld OPT = 1e11;

vector<lld> vec;
stack<lld> nums;
char c;
lld a, b;

int rev ()
{
	if (vec.size() == 1 && vec[0] < OPT)
		return 1;
	int estado = 1;
	int pos = vec.size()-1, div_zero = 0;
	while (estado == 1 && pos >= 0) {
		//printf ("%d %lld\n", nums.size(), vec[pos]);
		if (OPT > vec[pos])
			nums.push (vec[pos]);
		else if (nums.size () > 1) {
			b = nums.top();
			nums.pop ();
			a = nums.top();
			nums.pop ();
			//printf ("%d %d\n", a, b);
			switch (vec[pos]) {
				case (lld)OPT+1: nums.push(a + b);
							break;
				case (lld)OPT+2: nums.push(a - b);
							break;
				case (lld)OPT+3: nums.push(a * b);
							break;
				case (lld)OPT+4: if (b == 0) {
									 div_zero = 1;
									 nums.push (1);
								 }
							else
								nums.push(a / b);
							break;
			}
		}
		else
			estado = 0;
		pos--;
	}
	if (nums.empty() || nums.size() > 1)
		estado = 0;
	if (div_zero && estado == 1)
		estado = 2;
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
		if (vec.size() == 1 && vec[0] < OPT) {
			estado = 1;
			nums.push (vec[0]);
		}
		else if (vec.size())
			estado = rev ();
		else
			estado = 0;
		if (estado == 1 && (nums.size() > 1 || nums.empty()))
			estado = 0;
		if (estado == 1)
			printf ("The answer is %lld.\n", nums.top());
		else if (estado == 2)
			printf ("Division by zero.\n");
		else
			printf ("Invalid expression.\n");
		while (!nums.empty())
			nums.pop();
		vec.clear();
		if (c != EOF)
			c = getchar ();
	}
	return 0;
}
