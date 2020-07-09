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

const int N = 2e5 + 100;

int q, n;
string s, t;
map<char, int> mp;
int bit[N];

void add (int p, int v) {
	while (p <= n) {
		bit[p]+=v;
		p+=p&-p;
	}
}

int sum (int p) {
	int ret = 0;
	while (p >= 1) {
		ret += bit[p];
		p-=p&-p;
	}

	return ret;
}

int main () {
	ios::sync_with_stdio (false);
	cin.tie (0);

	cin >> q;
	while (q--) {
		mp.clear();
		cin >> n >> s >> t;
		bool ans = true;
		bool dupli = false;
		for (char c : s) mp[c]++;
		for (auto p : mp) if (p.y > 1) dupli = true;
		for (char c : t) mp[c]--;
		for (auto p : mp)
			if (p.y) {
				ans = false;
				break;
			}
		if (!ans) {
			cout << "NO\n";
			continue;
		}
		if (dupli) {
			cout << "YES\n";
			continue;
		}

		mp.clear();
		for (int i = 1; i <= n; i++) bit[i] = 0;
		for (int i = 0; i < n; i++)
			mp[s[i]] = i;
		
		int qSwaps = 0;
		for (int i = n-1; i >= 0; i--) {
			qSwaps += sum (mp[t[i]]+1);
			add (mp[t[i]]+1, 1);
		}
		// cout << qSwaps << '\n';
		if (qSwaps&1) {
			cout << "NO\n";
		} else
			cout << "YES\n";
	}

	return 0;
}
