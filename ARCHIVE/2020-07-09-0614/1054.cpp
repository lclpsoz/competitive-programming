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

int t, n, m;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	int cs = 1;
	while(t--) {
		cin >> n >> m;
		string s;
		int bef = 0;
		int ans = 0;
		vector<int> vec;
		vec.push_back(0);
		while(n--) {
			cin >> s;
			int v = stoi(s.substr(2, len(s)-2));
			// cout << "V: " << v << '\n';
			if(s[0] == 'S')
				vec.push_back(v);
			else if(s[0] == 'B' and len(vec) < 3) {
				ans = max(ans, v - vec.front());
				vec.clear();
				vec.push_back(v);
			}
			else {
				// cout << len(vec) << '\n';
				ans = max(ans, vec[1] - vec[0]);
				ans = max(ans, vec[2] - vec[0]);
				// cout << "here_1\n";
				for(int i = 3; i < len(vec); i+=2)
					ans = max(ans, vec[i] - vec[i-2]);
				for(int i = 4; i < len(vec); i+=2)
					ans = max(ans, vec[i] - vec[i-2]);
				// cout << "here_2\n";
				ans = max(ans, v - vec[len(vec)-1]);
				ans = max(ans, v - vec[len(vec)-2]);
				vec.clear();
				// cout << "here_3\n";
				vec.push_back(v);
			}
		}
		if(len(vec) > 2) {
			ans = max(ans, vec[1] - vec[0]);
			ans = max(ans, vec[2] - vec[0]);
			for(int i = 3; i < len(vec); i+=2)
				ans = max(ans, vec[i] - vec[i-2]);
			for(int i = 4; i < len(vec); i+=2)
				ans = max(ans, vec[i] - vec[i-2]);
			ans = max(ans, m - vec[len(vec)-1]);
			ans = max(ans, m - vec[len(vec)-2]);
			vec.clear();
		} else if(len(vec) <= 2) {
			// cout << ' ' << m - vec[0] << '\n';
			ans = max(ans, m - vec[0]);
		}
		vec.clear();
		cout << "Case " << cs++ << ": " << ans << '\n';
	}

	return 0;
}