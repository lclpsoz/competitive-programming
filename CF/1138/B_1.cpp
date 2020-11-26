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
string clown, acrobat;
vector<int> ans;
vector<int> zero, oC, oA, both;

void no () {
	printf ("-1\n");
	exit (0);
}

void cpy (vector<int> &v, vector<int> &v2) {
	while (!v2.empty()) {
		v.push_back(v2.back());
		v2.pop_back();
	}
}

int main () {
	cin >> n >> clown >> acrobat;
	for (int i = 0; i < n; i++) {
		if (clown[i] == acrobat[i]) {
			if (clown[i] == '1') both.push_back (i);
			else zero.push_back (i);
		} else if (clown[i] == '1') oC.push_back (i);
		else oA.push_back (i);
	}
	int ax = len(both)/2;
	while (ax--) {
		ans.push_back (both.back());
		both.pop_back ();
	}
	ax = len(zero)/2;
	while (ax--) {
		ans.push_back (zero.back());
		zero.pop_back ();
	}

	if (len (oC) == len (oA)) {
		if (len (both))
			no();
		cpy (ans, oC);
	}
	else if (abs (len (oC)-len (oA)) > 1)
		no();
	else if (abs (len (oC)-len (oA)) == 1 and len (both) == 0)
		no();
	else if (len (oC) < len (oA)) {
		cpy (ans, oC);
		cpy (ans, both);
	}
	else {
		cpy (ans, oC);
		cpy (ans, zero);
	}

	for (int v : ans)
		printf ("%d ", v);
	putchar ('\n');
		

	return 0;
}
