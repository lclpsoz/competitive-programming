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

int dist(pair<int, int> a, pair<int, int> b) {
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int mdc(int a, int b) {
	if (b == 0)
		return a;
	return mdc(b, a % b);
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	vector<pair<int, int>> points(3);
	for (int i = 0; i < 3; i++) {
		int x, y;
		cin >> x >> y;
		points[i] = {x, y};
	}
	vector<int> lados;
	lados.push_back(dist(points[0], points[1]));
	lados.push_back(dist(points[0], points[2]));
	lados.push_back(dist(points[1], points[2]));

	for (int i = 0; i < 3; i++) {
		int x, y;
		cin >> x >> y;
		points[i] = {x, y};
	}
	vector<int> lados_outro;
	lados_outro.push_back(dist(points[0], points[1]));
	lados_outro.push_back(dist(points[0], points[2]));
	lados_outro.push_back(dist(points[1], points[2]));

	// for (int i = 0; i < 3; i++) {
	// 	cout << lados[i] << " " << lados_outro[i] << endl;
	// }

	vector<int> perm;
	perm.push_back(0);
	perm.push_back(1);
	perm.push_back(2);
	bool ans = false;
	vector<pair<int, int>> prop(3);
	do {
		prop[0] = {lados_outro[0] / mdc(lados_outro[0], lados[perm[0]]), lados[perm[0]] / mdc(lados_outro[0], lados[perm[0]])};
		prop[1] = {lados_outro[1] / mdc(lados_outro[1], lados[perm[1]]), lados[perm[1]] / mdc(lados_outro[1], lados[perm[1]])};
		prop[2] = {lados_outro[2] / mdc(lados_outro[2], lados[perm[2]]), lados[perm[2]] / mdc(lados_outro[2], lados[perm[2]])};

		if ((prop[0].first == prop[1].first && prop[1].first == prop[2].first) && (prop[0].second == prop[1].second && prop[1].second == prop[2].second))
			ans = true;
	} while (next_permutation(perm.begin(), perm.end()));

	if (ans)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}
