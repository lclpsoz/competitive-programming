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

string t;
vector<pii> swaps;
vector<pii> arr[30];

// Expected abc..('a' + (r-l + 1))
vector<pii> oneAlpha (int l, int r, string &s) {
	vector<pii> sw;
	for (int i = l; i <= r; i++)
		while (s[i] != ('a' + i-l)) {
			int nxt = l + (s[i] - 'a');
			swap (s[i], s[nxt]);
			sw.push_back ({i, nxt});
		}

	return sw;
}

vector<pii> twoAlpha (int l, int r, string &s) {
	vector<pii> sw;
	vector<int> pos[28];
	for (int i = l; i <= r; i++)
		if (s[i] != 'a' + (i-l)/26)
			pos[(i-l)/26].push_back (i);

	for (int i = 0; i <= 'z'-'a'; i++)
		while (!pos[i].empty()) {
			int p = pos[i].back();
			int nxt = pos[s[p]-'a'].back();
			pos[i].pop_back(), pos[s[p]-'a'].pop_back ();
			sw.push_back ({p, nxt});
			swap (s[p], s[nxt]);
			if (s[p] != i+'a')
				pos[i].push_back (p);
		}

	return sw;
}
vector<pii> threeAlpha (int l, int r, string &s) {
	vector<pii> sw;
	vector<int> pos[28];
	for (int i = l; i <= r; i++)
		if (s[i] != 'a' + (i-l)/676)
			pos[(i-l)/676].push_back (i);

	for (int i = 0; i <= 'z'-'a'; i++)
		while (!pos[i].empty()) {
			int p = pos[i].back();
			int nxt = pos[s[p]-'a'].back();
			pos[i].pop_back(), pos[s[p]-'a'].pop_back ();
			sw.push_back ({p, nxt});
			swap (s[p], s[nxt]);
			if (s[p] != i+'a')
				pos[i].push_back (p);
		}

	return sw;
}

int main () {
	ios::sync_with_stdio (false);
	cout.tie (0);
	
	cin >> t;
	if (len (t) <= 26) {
		cout << "? ";
		for (int i = 0; i < len (t); i++)
			cout << (char)('a' + i);
		cout << '\n';
		cout << flush;
		string ans;
		cin >> ans;
		swaps = oneAlpha (0, len (ans) - 1, ans);
	} else if (len (t) <= 676) {
		// Two "swaps"
		cout << "? ";
		for (int i = 0; i < len (t); i++)
			cout << (char)('a' + i/26);
		cout << '\n';
		cout << flush;
		string ans;
		cin >> ans;
		vector<pii> swapsFrst = twoAlpha (0, len (t)-1, ans);


		cout << "? ";
		for (int i = 0; i < len (t); i++)
			cout << (char)('a' + i%26);
		cout << '\n';
		cout << flush;
		cin >> ans;
		for (int i = 0; i < len (swapsFrst); i++) {
			pii p = swapsFrst[i];
			// cout << p.x << ' ' << p.y << '\n';
			swap (ans[p.x], ans[p.y]);
		}
		vector<pii> swapsSec;
		for (int i = 0; i < len(t); i+=26) {
			vector<pii> now = oneAlpha (i, min (len (ans)-1, i+25), ans);
			for (auto pp : now)
				swapsSec.push_back (pp);
		}
		swaps = swapsFrst;
		for (auto p : swapsSec)
			swaps.push_back (p);
	} else {
		// Three "swaps"
		cout << "? ";
		for (int i = 0; i < len (t); i++)
			cout << (char)('a' + i/676);
		cout << '\n';
		cout << flush;
		string ans;
		cin >> ans;
		swaps = threeAlpha (0, len (t)-1, ans);


		cout << "? ";
		for (int i = 0; i < len (t); i++)
			cout << (char)('a' + (i/26)%26);
		cout << '\n';
		cout << flush;
		cin >> ans;
		for (int i = 0; i < len (swaps); i++) {
			pii p = swaps[i];
			swap (ans[p.x], ans[p.y]);
		}
		for (int i = 0; i < len (t); i+=676) {
			vector<pii> ax = twoAlpha (i, min (i+675, len (t)-1), ans);
			for (auto p : ax)
				swaps.push_back (p);
		}


		cout << "? ";
		for (int i = 0; i < len (t); i++)
			cout << (char)('a' + i%26);
		cout << '\n';
		cout << flush;
		cin >> ans;
		for (int i = 0; i < len (swaps); i++) {
			pii p = swaps[i];
			// cout << p.x << ' ' << p.y << '\n';
			swap (ans[p.x], ans[p.y]);
		}
		// cout << "befSec = " << ans << '\n';
		for (int i = 0; i < len(ans); i+=26) {
			vector<pii> now = oneAlpha (i, min (len (ans)-1, i+25), ans);
			for (auto pp : now)
				swaps.push_back (pp);
		}
	}


	for (int i = 0; i < len (swaps); i++) {
		pii p = swaps[i];
		swap (t[p.x], t[p.y]);
	}
	cout << "! " << t << '\n' << flush;

	return 0;
}
