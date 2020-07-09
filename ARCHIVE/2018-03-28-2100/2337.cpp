#include <bits/stdc++.h>
using namespace std;

long long mdc (long long a, long long b) {
	if (b == 0)
		return a;
	return mdc (b, a%b);
}

int i, x;
long long mat[2][41], d;

int main ()
{
	mat[0][1] = 2;
	mat[0][2] = 3;
	mat[1][1] = 2;
	mat[1][2] = 4;
	for (i = 3; i < 41; i++) {
		mat[0][i] = mat[0][i-1] + mat[0][i-2];
		mat[1][i] = 1LL << i;
	}
	for (i = 1; i < 41; i++) {
		d = mdc (mat[0][i], mat[1][i]);
		mat[0][i] /= d;
		mat[1][i] /= d;
	}
	while (scanf ("%d", &x) != EOF)
		printf ("%lld/%lld\n", mat[0][x], mat[1][x]);

	return 0;
}
