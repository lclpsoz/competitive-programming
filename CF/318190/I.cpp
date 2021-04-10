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

template<typename T>
const T INF = (is_same<T, int>::value ? 1e9 : 1e18);
const ld EPS = 1e-9;
const int MOD = 1;

inline int fcmp (ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

inline int mod (ll x, int m = MOD) {
	int ret = (int)x%m;
	if (ret < 0)
		ret += m;
	return ret;
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////



int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	// int n;
	// cin >> n;
	// vector<vi> vec(n+1, vi(n+1, 0));
	// for (int i = 1; i <= n; i++)
	// 	vec[i][i] = 1;
	// for (int i = 1; i <= n; i++)
	// 	for (int j = 1; j <= n; j++)
	// 		cout << vec[i][j] << " \n"[j==n];
	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j  <= n-i; j++) {
	// 		for (int l = 1; l <= n; l++)
	// 			vec[j][l] = vec[j+1][l] - vec[j][l];
	// 	}
	
	// 	cout << "After " << i << "'\n";
	// 	for (int _i = 1; _i <= n-i; _i++) {
	// 		cout << _i << ": ";
	// 		for (int j = 1; j <= n; j++)
	// 			cout << ' ' << vec[_i][j];
	// 		cout << '\n';
	// 	}
	// 	cout << '\n';
	// }

	int n;
	cin >> n;
	vector<ll> ans;
	if (n == 1)
		cout << "1\n";
	else if (n > 32)
		cout << "IMPOSSIBLE\n";
	else {
		int v1, v2;
		cin >> v1 >> v2;
		// vi vec(n);
		// for (int &x : vec)
		// 	cin >> x;
		// vec.pop_back();
		// reverse(ALL(vec));
		// if (vec.back() == 0)
		// 	ans.push_back(-1);
		// else
		// 	ans.push_back(1);
		// ll now = 1;
		// cerr << "HERE!!\n";
		// while (LEN(vec) > 1) {
		// 	vector<ll> bef = ans;
		// 	now *= 2;
		// 	ans.clear();
		// 	if (vec.back() == 0) {
		// 		vec.pop_back();
		// 		if (vec.back() == 0)
		// 			ans.push_back(-1);
		// 		else
		// 			ans.push_back(now);
		// 		while (LEN(bef)) {
		// 			ans.push_back(ans.back()+bef.back());
		// 			bef.pop_back();
		// 		} 
		// 	}
		// 	else {
		// 		vec.pop_back();
		// 		if (vec.back() == 0)
		// 			ans.push_back(-now);
		// 		else
		// 			ans.push_back(1);
		// 		while (LEN(bef)) {
		// 			ans.push_back(ans.back()+bef.back());
		// 			bef.pop_back();
		// 		} 

		// 	}
		// }
		// cerr << *max_element(ALL(ans)) << ' ' << *min_element(ALL(ans)) << '\n';
		// if (*max_element(ALL(ans)) > 1e9 or *min_element(ALL(ans)) < 1e9)
		// 	cout << "IMPOSSIBLE\n";
		// else {
		// 	// reverse(ALL(ans));
		// 	for (int i = 0; i < n; i++)
		// 		cout << ans[i] << " \n"[i==n-1];
		// }
	}


	return 0;
}
