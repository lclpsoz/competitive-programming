#include "bits/stdc++.h"
using namespace std;

// -------------------------------
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

int mdc (int a, int b) {
	if (a == 0) return b;
	return mdc (b%a, a);
}

int mmc (int a, int b) {
	return (a*b)/mdc (a, b);
}

int main () {
	int x, y, z;
	scanf ("%d %d %d", &x, &y, &z);
	if (mmc (x, y) <= z)
		printf ("yes\n");
	else
		printf ("no\n");
	return 0;
}