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

int n;
const int N = 1e5 + 1;

vector<int> a(N);

bool dfs(int i, int last, bool up, int l, int size) {
	cout << size << endl;
	if (i == n)
		return true;

	bool local_ans = false;
	if (a[i] != -1) {
		int diff = a[i] - last;
		if (up && diff < 0)
			return false;
		if (!up && diff > 0)
			return false;

		if (!up && size == -1 && i >= 2) {
			local_ans |= dfs(i + 1, a[i + 1], true, i + 1, i + 1);
			local_ans |= dfs(i + 1, a[i + 1], true, i + 1, -1);
		}
		if (!up && l - i + 1 == size)
			local_ans |= dfs(i + 1, a[i + 1], true, i + 1, size);

		local_ans |= dfs(i + 1, a[i], up, l, size);
		if (i - l + 1 >= 2)
			 local_ans |= dfs(i + 1, a[i], !up, l, size);
	}
	// } else {
	// 	if (up)
	// 		return dfs(i + 1, 1e9, false) || dfs(i + 1, max(last, a[i + 1]), true);
	// 	else
	// 		return dfs(i + 1, a[i], false) || dfs(i + 1, a[i], false);
	// }

	return local_ans;
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	bool ans = dfs(1, a[0], true, 0, -1);
	if (ans) {
		cout << "Y" << endl;
	} else {
		cout << "N" << endl;
	}
	
	return 0;
}
