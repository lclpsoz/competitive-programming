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
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

int main () {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	string s;
	cin >> n;
	while(n--) {
		cin >> s;
		bool arr[300];
		int amnt = 4;
		memset(arr, 0, sizeof arr);
		arr['A'] = 1;
		arr['Q'] = 1;
		arr['J'] = 1;
		arr['K'] = 1;
		for(int i = 0; i < len(s); i++) {
			amnt -= arr[s[i]];
			arr[s[i]] = 0;
		}
		if(amnt == 0)
			cout << "Aaah muleke\n";
		else
			cout << "Ooo raca viu\n";
	}

	return 0;
}
