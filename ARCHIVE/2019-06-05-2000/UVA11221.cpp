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

int t;
vector<char> vec;
char mat[102][102];

bool isSq () {
	int sq = sqrt (len (vec));
	if (sq*sq != len (vec))
		return false;
	else {
		for (int i = 0; i < len (vec); i++)
			mat[i/sq][i%sq] = vec[i];
		for (int i = 0; i < len (vec); i++)
			if (mat[i%sq][i/sq] != vec[i]) return false;
			
		for (int i = len (vec) - 1; i >= 0; i--)
			if (mat[i/sq][i%sq] != vec[len (vec) - 1 - i]) return false;
		for (int i = len (vec) - 1; i >= 0; i--)
			if (mat[i%sq][i/sq] != vec[len (vec) - 1 - i]) return false;
	}
	
	return true;
}

int main () {
	cin.tie (0);
	ios::sync_with_stdio (false);
	
	for (int i = 1; i <= 100; i++) {
		int sq = sqrt (i*i);
		
		if (sq != i)
			cout << "sq: " << sq << " vs i: " << i << '\n';
	}
		
	
	int caso = 1;
	cin >> t;
	cin.ignore();
	while (t--) {
		vec.clear();
		string s;
		getline (cin, s);
		for (int i = 0; i < len (s); i++)
			if (s[i] >= 'a' and s[i] <= 'z')
				vec.push_back (s[i]);
			
			
		cout << "Case #" << caso++ << ":\n";
		if (len (vec) == 0) {
			cout << 0 << '\n';
			
		} else if (!isSq ())
			cout << "No magic :(\n";
		else
			cout << sqrt (len (vec)) << '\n';
	}

	return 0;
}
