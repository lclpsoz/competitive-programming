#include <bits/stdc++.h>
using namespace std;

int n, n1, d1, n2, d2, n3, d3, d;
char opr;

int mdc (int a, int b) {
	if (b == 0)
		return a;
	return mdc (b, a%b);
}

int main ()
{
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%d / %d %c %d / %d", &n1, &d1, &opr, &n2, &d2);
		if (opr == '+') {
			n3 = (n1*d2)+(n2*d1);
			d3 = (d1*d2);
		}
		else if (opr == '-') {
			n3 = (n1*d2)-(n2*d1);
			d3 = (d1*d2);
		}
		else if (opr == '*') {
			n3 = n1*n2;
			d3 = d1*d2;
		}
		else if (opr == '/') {
			n3 = n1*d2;
			d3 = n2*d1;
		}

		d = mdc(d3, n3);
		printf ("%d/%d = %d/%d\n", n3, d3, n3/abs(d), d3/abs(d));
	}
	return 0;
}
