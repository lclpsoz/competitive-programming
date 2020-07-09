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
string s;

void no() {
	cout << ":(\n";
	exit (0);
}

int main () {
	ios::sync_with_stdio (false);
	cin.tie (0);
	cin >> n >> s;
	if (n%2 == 1) no ();
	if (s[0] != '?' and s[0] != '(') no();
	if (s[n-1] != '?' and s[n-1] != ')') no();
	s[0] = '(', s[n-1] = ')';

	int qnt = 0;
	stack<int> st;
	for (int i = 1; i < n-1; i++) {
		if (s[i] == '(')
			++qnt;
		else if (s[i] == '?')
			st.push (i);
		else if (qnt)
			--qnt;
		else if (len (st)) {
			s[st.top()] = '(';
			st.pop();
		}
		else
			no ();
	}
	// cout << s << '\n';
	while (len (st)) st.pop();
	qnt = 0;
	for (int i = n-2; i; i--) {
		if (s[i] == ')')
			++qnt;
		else if (s[i] == '?')
			st.push (i);
		else if (qnt)
			--qnt;
		else if (len (st)) {
			s[st.top()] = ')';
			st.pop();
		}
		else
			no ();
	}
	// cout << s << '\n';
	bool now = false;
	for (int i = 1; i < n-1; i++) {
		if (s[i] == '?') {
			s[i] = now ? ')' : '(';
			now = !now;
		}
	}
	cout << s << '\n';

	

	return 0;
}
