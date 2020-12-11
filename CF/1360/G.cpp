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

int t;
int mat[55][55];
int amnt[55];

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	cin >> t;
	while(t--) {
		int n, m, a, b;
		cin >> n >> m >> a >> b;
		if(n*a > n*m or m*b > n*m or a > m or b > n)
			cout << "NO\n";
		else {
			memset(mat, 0, sizeof mat);
			set<pii> b_now;
			for(int i = 0; i < m; i++)
				b_now.insert({-b, i});
			bool ans = true;
			for(int i = 0; i < n; i++) {
				int a_now = a;
				vpii cols;
				while(LEN(b_now) and a_now) {
					pii p = *b_now.begin();
					b_now.erase(b_now.begin());
					mat[i][p.y] = 1;
					a_now--;
					p.x++;
					// cout << "p = " << p.x << ' ' << p.y << '\n';
					if(p.x != 0)
						cols.push_back(p);
				}
				for(pii p :cols)
					b_now.insert(p);
				// for(int j = 0; a_now and j < m; j++) {
				// 	if(amnt[j]) {
				// 		mat[i][j] = 1;
				// 		amnt[j]--;
				// 		a_now--;
				// 	}
				// }
				if(a_now) {
					ans = false;
					break;
				}
			}
			
			if(!ans or LEN(b_now))
				cout << "NO\n";
			else {
				cout << "YES\n";
				for(int i = 0; i < n; i++) {
					for(int j = 0; j < m; j++)
						cout << mat[i][j];
					cout << '\n';
				}
			}
		}
	}

	return 0;
}
