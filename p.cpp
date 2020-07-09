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

bitset<N> not_prime;
vector<int> primesFiltered(N, 0);
vector<int> adj[N];

int main () {

	for (int p : primesFiltered) {
		string s = to_string(p);
		for (int i = 0; i < 4; i++) {
			int ax  = s[i];
			for (int j = '0'; j <= '9'; j++) {
				s[i] = j;
				int now = stoi (s);
				if (now >= 1000 and !not_prime[now])
					adj[p].push_back (now);
			}
			s[i] = ax;
		}
	}

	return 0;
}
