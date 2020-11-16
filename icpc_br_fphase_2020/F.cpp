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

int g[2], p[2];
bool sv;

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	string s;
	cin >> s;

	for(char c : s)
	{
		if(c == 'Q')
		{
			if(g[0] == 2 || g[1] == 2)
			{
				cout << g[0] << (g[0] == 2 ? "(winner)" : "") << " - " << g[1] << (g[1] == 2 ? "(winner)" : "") << endl;
			}
			else
			{
				cout << g[0] << " (" << p[0] << (!sv ? "*" : "") << ") - " << g[1] << " (" << p[1] << (sv ? "*" : "") << ")" << endl;
			}
		}
		else
		{
			if(c == 'R') sv = !sv;
			p[sv]++;
			if(p[sv] == 10 || (p[sv] >= 5 && p[sv] - p[!sv] >= 2))
			{
				p[sv] = p[!sv] = 0;
				g[sv]++;
			}
		}
	}

	return 0;
}
