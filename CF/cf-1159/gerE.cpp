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

void brute (int n) {
	map<string, vector<string>> mp;
	vec.clear();
	for (int i = 1; i <= n; i++)
		vec.push_back (i);
	do {
		string key = "";
		for (int i = 1; i <= n; i++) {
			// printf ("%d%c", vec[i-1], " \n"[i==n]);
			key += (char)('0'+vec[i-1]);
		}
		string ax = key;
		for (char &c : ax)
			c++;
		all.push_back (ax);
		// printf ("  nxt: ");
		string now = "";
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j <= n; j++)
				if (j == n) {
					// printf ("%d ", len (vec)+1);
					now += ((char)('0'+len(vec)+1));
				}
				else if (vec[j] > vec[i]) {
					// printf ("%d ", j+1);
					now += ((char)('0'+j+1));
					break;
				}
		}
		// putchar ('\n');
		// if (st.count (now))
		// 	cout << now << '\n';
		mp[now].push_back (key);
		st.insert (now);
	} while (next_permutation (vec.begin(), vec.end()));
	cout << "INPUT: " << '\n';
	for (auto pp : mp)
		for (int i = 0; i < len (pp.y); i++)
			cout << n << ' ' << pp.x << '\n';
	cout << "AC: " << '\n';
	for (auto pp : mp)
		for (int i = 0; i < len (pp.y); i++)
			cout << pp.y[i] << '\n';

	// set<string> st;
	// for (auto pp : mp) {
	// 	// st.insert (pp.x.substr (0, 3));
	// 	st.insert (pp.x);
	// 	// cout << pp.x << '\n';
	// 	// for (auto p : pp.y)
	// 		// cout << "  " << p << '\n';
	// }
	// for (string s : st)
	// 	cout << s << '\n';
	// cout << '\n';
	// for (string s : st) {
	// 	for (int i = 0; i < len (s); i++) {
	// 		string now = s.substr (0, i) + (char)(i+'0'+2) + s.substr (i+1, len(s)-i-1);
	// 		if (!st.count (now))
	// 			cout << s << ' ' << now << '\n';
				
	// 	}
	// }
}

int main () {
	// brute (2);
	// brute (3);
	// brute (4);
	// brute (5);
	// cout << "\n6\n";
	// brute (6);
	// brute (3);

	// for (string s : all) {
	// 	vector<int> v;
	// 	for (char c : s)
	// 		v.push_back (c-'0');
	// 	check (v, s);
	// }

	return 0;
}
