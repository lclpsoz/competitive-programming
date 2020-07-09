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

const int MAXV = 2e9l;
int nums[] = {2, 3, 5, 7};
vector<int> vec;

void solve (int p = 0, ll val = 1) {
	if (p == 4) {
		vec.push_back ((int)val);
		return;
	}
	
	for (int i = 0; val <= MAXV; i++) {
		solve (p+1, val);
		val *= nums[p];
	}
}

string prt (int n) {
	if (n%10 == 1 and n%100 != 11)
		return "st";
	else if (n%10 == 2 and n%100 != 12)
		return "nd";
	else if (n%10 == 3 and n%100 != 13)
		return "rd";
	else
		return "th";
}

int main () {
// 	cin.tie (0); cout.tie (0);
// 	ios::sync_with_stdio (false);
	solve ();
	sort (vec.begin(), vec.end());
	int n;
	while (cin >> n, n) {
		string str = prt (n);
		cout << "The " << n << str << " humble number is " << vec[n-1] << ".\n";
	}

	return 0;
}
