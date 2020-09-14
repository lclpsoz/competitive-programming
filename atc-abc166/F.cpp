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

using pp = pair<int, pair<int, int>>;

const int N = 1e5 + 10;

int n;
int val[4];
int ch[4];
string vv[] = {"AB", "AC", "BC"};
vector<int> pos[3];
char ans[N];
string inp[N];
map<int, map<int, map<int, bool>>> mp;
int total = 0;

bool solve(int p, int a, int b) {
	if(a+b > total or a < 0 or b < 0) return 0;
	if(p == n+1) return true;
	if(mp.count(p) and mp[p].count(a) and mp[p][a].count(b)) return mp[p][a][b];
	bool &ret = mp[p][a][b];
	if(inp[p] == "AB")
		ret = solve(p+1, ) ||
}

int main () {
	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.precision(10);
	int a, b, c;
	cin >> n >> a >> b >> c;
	string s;
	for(int i = 1; i <= n; i++) 
		cin >> inp[i];
	total += a + b + c;
	cout << solve(1, a, b) << '\n';

	return 0;
}
