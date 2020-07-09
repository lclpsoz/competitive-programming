#include <bits/stdc++.h>
using namespace std;

int n;
char c;
int zero, one;
bool turn;

int sum_digits (int x)
{
	int r = 0;
	while (x) {
		r += x%10;
		x /= 10;
	}

	return r;
}

int main ()
{
	while (scanf ("%d", &n), n) {
			getchar (); // '\n'
		while (n--) {
			turn = false;
			zero = one = 0;
			while (c = getchar (), c != '\n') {
				if (turn)
					one += c-'0';
				else
					zero += c-'0';
				turn = !turn;
			}

			printf ("%d\n", sum_digits(zero)+sum_digits(one));
		}
	}

	return 0;
}
