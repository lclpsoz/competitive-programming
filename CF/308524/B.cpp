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

inline int fcmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
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

	int t; cin >> t;
	while(t--)
	{
		int q, m; cin >> q >> m;
		vector<vector<bool>> x(q, vector<bool>(4, true));

		while(m--)
		{
			for(int i = 0; i < q; i++)
			{
				char a, b;
				cin >> a >> b;
				a -= 'A';
				if(b == 'T')
				{
					for(int j = 0; j < 4; j++) x[i][j] = false;
					x[i][a] = true;
				}
				else x[i][a] = false;
			}
		}

		for(int i = 0; i < q; i++)
		{
			if(count(ALL(x[i]), true) > 1) cout << "?" << " \n"[i == q - 1];
			else
			{
				for(int j = 0; j < 4; j++)
					if(x[i][j])
						cout << char('A' + j) << " \n"[i == q - 1];
			}
		}
	}

	return 0;
}
