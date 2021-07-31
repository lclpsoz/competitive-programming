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

const int N = 260;
int cnt[N];
int use[10];

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	// int n, k; cin >> n >> k;

	// auto eval = [&](const vi& a) {
	// 	s
	// };

	// vi event;

	// while(n--) {
	// 	char c;
	// 	cin >> c;

	// 	if(c == 'C') {
	// 		int r;
	// 		cin >> r;
	// 		vi a(k, 0);
	// 		for(int i = 0; i < r; i++)
	// 		{
	// 			int b;
	// 			cin >> b;
	// 			a[b - 1]++;
	// 		}

	// 		int m = eval(a);
	// 		event.push_back(m);
	// 		cnt[m]--;
	// 	}
	// 	else if(c == 'D') {
	// 		int id; cin >> id;
	// 		cnt[event[id - 1]]--;
	// 	}
	// 	else {

	// 	}
	// }

	return 0;
}
