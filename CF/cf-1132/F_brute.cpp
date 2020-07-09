#include "bits/stdc++.h"
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

int n;
char arr[510];
char fil[510];

bool over () {
	for (int i = 0; i < n; i++)
		if (fil[i] != '-') return false;
	return true;
}

void clear (int p) {
	char c = fil[p];
	for (int i = p-1; i >= 0; i--)
		if (fil[i] != '-' and fil[i] != c) break;
		else fil[i] = '-';
	for (int i = p+1; i < n; i++)
		if (fil[i] != '-' and fil[i] != c) break;
		else fil[i] = '-';
	fil[p] = '-';
}

int brute (int now) { 
// 	printf ("now: %d | ", now);
// 	for (int i = 0; i < n; i++)
// 		putchar (fil[i]);
// 	putchar ('\n');
// 	putchar ('-');
	if (over ()) return 0;
	int ret = 1e9;
	char aux[510];
	for (int i = 0; i < n; i++)
		if (fil[i] != '-') {
			for (int j = 0; j < n; j++)
				aux[j] = fil[j];
			clear (i);
			ret = min (ret, brute (now+1) + 1);
			for (int j = 0; j < n; j++)
				fil[j] = aux[j];
		}
		
	return ret;
}

int main () {
	int REMOVER;
	scanf ("%d", &REMOVER);
	while (REMOVER--) {
		scanf ("%d", &n);
		scanf ("%s", arr);
		fil[0] = arr[0];
		for (int i = 1; i < n; i++)
			if (arr[i] != arr[i-1])
				fil[i] = arr[i];
			else
				fil[i] = '-';
		
		printf ("%d\n", brute (1));
	}
	
	return 0;
}
