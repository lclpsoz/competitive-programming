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
		memset(arr, 0, sizeof arr);
		vector<char> vec = {'A', 'K', 'J', 'Q'};
		for(int i = 0;len(vec) and i < len(s); i++) {
			if(s[i] == vec.back()) vec.pop_back();
		}
		if(len(vec) == 0)
			cout << "Agora vai\n";
		else
			cout << "Agora apertou sem abracar\n";
	}

	return 0;
}
