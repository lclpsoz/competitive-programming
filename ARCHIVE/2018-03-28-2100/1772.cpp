#include <cstdio>

unsigned a, b, x, y;
unsigned aux, mini, maxi, ans;

int main ()
{
	while (scanf ("%u %u", &a, &b), a || b) {
		mini = maxi = a;
		for (int i = 0; i < b; i++) {
			scanf ("%u %u", &x, &y);
			aux = 0;
			if (x == y && a & 1 << x) {
				a ^= 1 << x;
				a |= 1 << (x+1);
			}
			else {
				aux = (a & (1 << x));
				a |= 1 << x;
				if (!(a & 1 << y))
					a ^= 1 << x;
				a |= 1 << y;
				if (!aux)
					a ^= 1 << y;
				if (a < mini)
					mini = a;
				if (a > maxi)
					maxi = a;
			}
		}
		printf ("%u %u %u\n", a, maxi, mini);
	}
	return 0;
}
