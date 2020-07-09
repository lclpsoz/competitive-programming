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

char aux[100];
vector<string> inp, conv, ans;
map<string, int> mp;

string simple (string &s) {
	for (int i = 0; i < len (s); i++)
		aux[i] = tolower(s[i]);
	
	aux[len (s)] = '\0';
	sort (aux, aux + len (s));
	return aux;
}

int main () {
	cin.tie (0);
	ios::sync_with_stdio (false);
	
	string s;
	while (cin >> s, s != "#") {
		if (len (s) == 1) {
			ans.push_back (s);
			continue;
		}
		inp.push_back (s);
		conv.push_back (simple (s));
		mp[conv.back()]++;
	}
	for (int i = 0; i < len (inp); i++)
		if (mp[conv[i]] == 1)
			ans.push_back (inp[i]);
	sort (ans.begin(), ans.end());
	for (string &s : ans)
		cout << s << '\n';

	return 0;
}
