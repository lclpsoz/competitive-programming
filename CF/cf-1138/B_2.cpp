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
set<int> ans;
vector<int> zero, oC, oA, both;
vector<int> _zero, _oC, _oA, _both;

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

void divide () {
	int mn = min (len (oA), len (oC));
	for (int i = 0; i < mn; i++) {
		ans.insert (oC.back());
		oC.pop_back();
		oA.pop_back();
	}
}

void useBoth () {
	while (len (both) and (len (oC) or len (oA))) {
		if (len (oC)) {
			ans.insert (oC.back());
			oC.pop_back();
		} else {
			ans.insert (both.back());
			oA.pop_back();
		}
		both.pop_back ();
	}
}

void useZero () {
	while (len (zero) and (len (oC) or len (oA))) {
		if (len (oC)) {
			ans.insert (zero.back());
			oC.pop_back();
		} else {
			ans.insert (oA.back());
			oA.pop_back();
		}
		zero.pop_back ();
	}
}

void useAllBoth () {
	int ax = len(both)/2;
	while (ax--) {
		ans.insert (both.back());
		both.pop_back ();
		both.pop_back ();
	}
}

void useAllZero () {
	int ax = len(zero)/2;
	while (ax--) {
		ans.insert (zero.back());
		zero.pop_back ();
		zero.pop_back ();
	}
}

void callF (int id) {
	if (id == 0) divide();
	else if (id == 1) useBoth();
	else if (id == 2) useZero();
	else if (id == 3) useAllBoth();
	else if (id == 4) useAllZero();
}

// Possible or not
bool brute () {
	int nn = (1<<n);
	for (int i = 0; i < nn; i++) {
		if (__builtin_popcount (i) != n/2) continue;
		int qC = 0, qA = 0;
		for (int j = 0; j < n; j++)
			if ((1<<j)&i)
				qC += clown[j] == '1';
			else
				qC += acrobat[j] == '1';
		if (qA == qC) {
			printf ("%d\n", nn);
			return true;
		}
	}
	
	return false;
}

bool check () {
	int qC, qA; qC = qA = 0;
	for (int i = 0; i < n; i++)
		if (ans.count (i))
			qC += clown[i] == '1';
		else
			qA += acrobat[i] == '1';

	return qC == qA;
}

int main () {
	cin >> n >> clown >> acrobat;
	for (int i = 0; i < n; i++) {
		if (clown[i] == acrobat[i]) {
			if (clown[i] == '1') _both.push_back (i);
			else _zero.push_back (i);
		} else if (clown[i] == '1') _oC.push_back (i);
		else _oA.push_back (i);
	}

	vector<int> perm;
	for (int i = 0; i < 5; i++)
		perm.push_back (i);

	do {
		ans.clear();
		both = _both;
		zero = _zero;
		oC = _oC;
		oA = _oA;
		for (int i = 0; i < 5; i++)
			callF (perm[i]);
	} while (len (ans) != n/2 and next_permutation (perm.begin(), perm.end()));
	// for (int v : ans)
	// 	printf ("|%d ", v+1);
	// putchar ('\n');

	if (len (ans) != n/2) {
		if (brute()) {
			cout << clown << '\n' << acrobat << '\n';
			printf ("WRONG!\n");
			for (int v : ans)
				printf ("%d ", v+1);
			putchar ('\n');
		}
		no();
	}

	for (int v : ans)
		printf ("%d ", v+1);
	putchar ('\n');

	if (!check()) {
		cout << clown << '\n' << acrobat << '\n';
		for (int v : perm)
			printf ("%d ", v);
		putchar ('\n');
		
		printf ("WRONG!\n");
	}

	return 0;
}
