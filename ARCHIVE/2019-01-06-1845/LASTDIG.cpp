#include "bits/stdc++.h"
using namespace std;

int powMod (int b, int p) {
	int m = 10;
	int ans = 1;
	while (p) {
		if (p&1) ans = (ans * b) % m;
		b = (b * b) % m;
		p >>= 1;
	}
	
	return ans;
}

int main () {
	int t, b, p;
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d %d", &b, &p);
		printf ("%d\n", powMod (b, p));
	}

	return 0;
}
