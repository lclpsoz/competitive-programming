#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e4+10;

int n;
int alt[MAXN];
int esq[MAXN];
int ans;

int main ()
{
	scanf ("%d", &n);

	// Diagonals from LEFT!
	int x = 1; // Starting left!
	esq[0] = 1;
	scanf ("%d", &alt[0]);
	for (int i = 1; i < n; i++) {
		scanf ("%d", &alt[i]);
		alt[i] > x ? x++ : x = alt[i];
		esq[i] = x;
	}

	// Diagonals from RIGHT!
	x = 1; // Starting right!
	ans = 1;
	for (int i = n-2; i >= 0; i--) {
		alt[i] > x ? x++ : x = alt[i];
		ans = max (ans, min (x, esq[i]));
	}

	printf ("%d\n", ans);

	return 0;
}
