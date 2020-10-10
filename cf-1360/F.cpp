#include "bits/stdc++.h"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/pb_ds/assoc_container.hpp"
using namespace std;
////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define LEN(x) ((int)(x).size())
#define ALL(x) x.begin(), x.end()
using ll = long long;
using llu = long long unsigned;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vpii = vector<pii>;

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

set<char> possible[12];

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int n, m, t;

	cin >> t;
	while(t--) {
		vector<string> vec;
		cin >> n >> m;
		for(int i = 0; i < m; i++)
			possible[i].clear();
		for(int i = 0; i < n; i++) {
			string s;
			cin >> s;
			vec.push_back(s);
			for(int j = 0; j < m; j++)
				possible[j].insert(s[j]);
		}
		bool ans = true;
		for(int i = 0; i < n; i++)
			for(int j = 0; ans and j < n; j++) {
				int q = 0;
				for(int k = 0; k < m; k++)
					q += vec[i][k] != vec[j][k];
				ans = ans and q <= 2;
			}
		if(!ans)
			cout << "-1\n";
		else {
			vi dig(m+1);
			vector<vector<char>> chars(m+1);
			for(int i = 0; i < m; i++)
				for(char v : possible[i])
					chars[i].push_back(v);
			string now = vec[0];
			while(dig[m] == 0) {
				for(int i = 0; i < m; i++)
					now[i] = chars[i][dig[i]];
				ans = true;
				for(int j = 0; ans and j < n; j++) {
					int q = 0;
					for(int k = 0; k < m; k++)
						q += now[k] != vec[j][k];
					ans = ans and q <= 1;
				}
				if(ans) {
					cout << now << '\n';
					break;
				}
				int p = 0;
				dig[p]++;
				while(p < m and dig[p] == LEN(chars[p])) {
					dig[p] = 0;
					++p;
					dig[p]++;
				}
			}
			if(!ans)
				cout << "-1\n";
		}
	}

	return 0;
}
