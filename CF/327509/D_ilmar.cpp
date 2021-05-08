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

int fdist(pair<int, int> P1, pair<int, int> P2) {
	return (P1.first - P2.first) * (P1.first - P2.first) + (P1.second - P2.second) * (P1.second - P2.second);
}

int bin_search1(pair<int, int> pos, int l, int r, int dist, bool x) {
	pair<int, int> pos_test = pos;
	while (l <= r) {
		int m = (l + r) / 2;
		if (x)
			pos_test.first = m;
		else
			pos_test.second = m;

		if (fdist(pos_test, pos) <= dist) {
			r = m;
		} else {
			l = m + 1;
		}
	}
	if (x)
		pos_test.first = l;
	else
		pos_test.second = l;
	if (fdist(pos_test, pos) == dist)
		return l;
	return -1;
}

int bin_search2(pair<int, int> pos, int l, int r, int dist, bool x) {
	pair<int, int> pos_test = pos;
	while (l <= r) {
		int m = (l + r) / 2;
		if (x)
			pos_test.first = m;
		else
			pos_test.second = m;

		if (fdist(pos_test, pos) <= dist) {
			l = m;
		} else {
			r = m - 1;
		}
	}
	if (x)
		pos_test.first = l;
	else
		pos_test.second = l;
	if (fdist(pos_test, pos) == dist)
		return l;
	return -1;
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int n;
	cin >> n;
	pair<int, int> pos;
	pos = {0, 0};

	// 1 - (x - pos.first) ** 2 + (y - pos.second) ** 2 = dist
	// pos = {x + sqrt(dist), y} <- FIXME usar busca binaria?
	// 2 - (x - pos.first) ** 2 + (y - pos.second) ** 2 = dist
	// resolver sistema com as equacoes 1 e 2
	// um dos dois pontos e a solucao

	// E sempre possivel pegar as 7 esferas com 1000 de energia
	while (n--) {
		cout << pos.first << " " << pos.second << endl;
		int dist;
		cin >> dist;

		pair<int, int> pos_test = pos;
		pair<int, int> pos_new = pos;
		int border;

		if (border == -1) {
			border = bin_search1(pos, 0, pos.first, true, dist);
			pos_new.first = border;
		}

		if (border == -1) {
			border = bin_search1(pos, pos.first, 1e6, true, dist);
			pos_new.first = border;
		}

		if (border == -1) {
			border = bin_search1(pos, 0, pos.second, false, dist);
			pos_new.second = border;
		}

		if (border == -1) {
			border = bin_search1(pos, pos.second, 1e6, false, dist);
			pos_new.second = border;
		}

		cout << pos_new.first << " " << pos_new.second << endl;
		int new_dist;
		cin >> new_dist;
	}

	return 0;
}
