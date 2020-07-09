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

const int EN = 9;

vector<int> arr(15, 1);

void nxt (int n) {
	vector<int> vec(n, 0);
	for (int i = 0; i < n; i++) {
		if (i+1 < n)
			vec[i] += arr[i+1];
		if (i-1 >= 0)
			vec[i] += arr[i-1];
	}
	
	arr = vec;
}

int func (int n, int mov) {
	if (mov > EN)
		return 1e9;
	int r = 0;
	
	//printf ("(%d, %d)\n", n, mov);
	//for (int i = 0; i < mov; i++)
	//	printf ("| ");
	
	for (int i = 0; i < n; i++) {
		//printf ("%d ", arr[i]);
		r += arr[i];
	}
	//if (!r)
	//	printf (" <<<<<");
	//putchar ('\n');
	
	if (!r)
		return mov;
	if (mov == EN)
		return 1e9;
	r = 1e9;
	for (int i = 0; i < n; i++) {
		if (!arr[i])
			continue;
		//printf ("      [%d %d]\n", mov, i);
		vector<int> ax = arr;
		arr[i] = 0;
		nxt (n);
		r = min (r, func (n, mov+1));
		if (r == EN) {
			printf ("[%d %d]\n", mov, i);
			return r;
		}
		arr = ax;
	}
	
	return r;
}

int main () {
	int n;
	scanf ("%d", &n);
	printf ("%d\n", func (n, 0));
	
	return 0;
}
