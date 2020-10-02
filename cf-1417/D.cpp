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

int t, n;
vector<int> vec;
vector<pair<pii, int>> ans;

bool check() {
	for(int i = 1; i <= n; i++)
		if(vec[i] >= i)	return true;
	return false;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	cin >> t;
	while(t--) {
		cin >> n;
		int total = 0;
		int bef = -1;
		bool equal = true;
		int count_mov = 0;
		vec.clear();
		vec.push_back(-1);
		for(int i = 0; i < n; i++) {
			int x;
			cin >> x;
			total += x;
			vec.push_back(x);
			count_mov += (x >= i+1);
			if(bef == -1)
				bef = x;
			else if(bef != x)
				equal = false;
		}
		if(total%n or (!equal and count_mov == 0))
			cout << "-1\n";
		else if(equal)
			cout << "0\n";
		else {
			int target = total/n;
			for(int i = 2; i <= n; i++) {
				if(vec[i] >= i) {
					int x = vec[i]/i;
					ans.push_back({{i, 1}, x});
					vec[i] -= x*i;
					vec[1] += x*i;
				}
			}
			if(!check()) {
				cout <<"-1\n";
				continue;
			}
			// for(int i = 1; i <= n; i++)
			// 	cout << i << ": " << vec[i] << '\n';
			for(int j = 0; j < 1; j++) {
				for(int i = 2; i <= n; i++)
					if(vec[i] and vec[1]+vec[i] >= i) {
						ans.push_back({{1, i}, i-vec[i]});
						ans.push_back({{i, 1}, 1});
						vec[1] += vec[i];
						vec[i] = 0;
					}
				// cout << "vals = ";
				// for(int i = 1; i <= n; i++)
				// 	cout << vec[i] << ' ';
				// cout << '\n';

				if(!check())
					break;
			}
			// for(int i = 1; i <= n; i++)
			// 	cout << i << ": " << vec[i] << '\n';
			if(!check()) {
				cout << "-1\n";
				continue;
			}
			bool ok = true;
			for(int i = 2; ok and i <= n; i++) {
				// cout << i << ' ' << vec[i] << '\n';
				if(vec[i] > target) {
					ok=false;
				} else if(vec[i] < target) {
					ans.push_back({{1, i}, target-vec[i]});
					vec[1]-=target-vec[i];
					vec[i] = target;
				}
			}
			if(!ok or vec[1] != target or LEN(ans) >= 3*n) {
				cout << "-1\n";
			} else {
				cout << LEN(ans) << '\n';
				for(auto p : ans)
					cout << p.x.x << ' ' << p.x.y << ' ' << p.y << '\n';
				// for(int i = 1; i <= n; i++)
				// 	cout << i << ": " << vec[i] << '\n';
			}
			ans.clear();
		}

	}

	return 0;
}
