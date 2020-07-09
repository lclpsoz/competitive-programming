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

const int N = 310;

int n;
vector<pair<string, int>> arr[110];
char ans[N];

void solve (int p, string &now) {
	if (p == 0) {
		for (int i = 0; i < 2*n-2; i++)
			putchar (ans[i]);
		putchar ('\n');
		exit(0);
	}
	
	auto &s0 = arr[p][0];
	auto &s1 = arr[p][1];
	bool test = true;
	for (int i = 0; i < p; i++)
		if (s0.x[i] != now[i] or s1.x[p-1-i] != now[n-1-i])
			test = false;
	if (test) {
		ans[s0.y] = 'P';
		ans[s1.y] = 'S';
	} else {
		test = true;
		for (int i = 0; i < p; i++)
			if (s1.x[i] != now[i] or s0.x[p-1-i] != now[n-1-i])
				test = false;
		
		if (!test) // FAIL!!!
			return;
		ans[s0.y] = 'S';
		ans[s1.y] = 'P';
	}
	solve (p-1, now);
}

int main () {
 	cin.tie (0); cout.tie (0);
 	ios::sync_with_stdio (false);
	cin >> n;
	for (int i = 0; i < 2*n - 2; i++) {
		string s;
		cin >> s;
		arr[len (s)].emplace_back (s, i);
	}
	
	bool test = true;
	for (int i = 0; i < n-2; i++)
		if (arr[n-1][0].x[i+1] != arr[n-1][1].x[i])
			test = false;
	if (test) {
		string s = arr[n-1][0].x + arr[n-1][1].x.substr (n-2, 1);
		ans[arr[n-1][0].y] = 'P';
		ans[arr[n-1][1].y] = 'S';
		solve (n-2, s);
	}

	test = true;
	for (int i = 0; i < n-2; i++)
		if (arr[n-1][1].x[i+1] != arr[n-1][0].x[i])
			test = false;
	if (test) {
		string s = arr[n-1][1].x + arr[n-1][0].x.substr (n-2, 1);
		ans[arr[n-1][1].y] = 'P';
		ans[arr[n-1][0].y] = 'S';
		solve (n-2, s);
	}
	assert (false);
		
	return 0;
}
