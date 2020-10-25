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

const int SHIFT = 10;

int mat[100][100];
queue<pair<pii, pair<set<pii>, int>>> q;

void ins(pii p, pii p_t, pii p_aft, set<pii> used, int points) {
	if(used.count(p_t) == 0 and mat[p_t.x][p_t.y] == 1 and mat[p_aft.x][p_aft.y] == 0) {
		used.insert(p_t);
		q.push({p_aft, {used, points+1}});
	}
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int n, x0, y0;
	cin >> n >> x0 >> y0;
	memset(mat, -1, sizeof mat);
	for(int i = SHIFT+1; i <= SHIFT+8; i++)
		for(int j = SHIFT+1; j <= SHIFT+8; j++)
			mat[i][j] = 0;
	while(n--) {
		int x, y;
		cin >> x >> y;
		mat[x+SHIFT][y+SHIFT] = 1;
	}
	q.push({{x0+SHIFT, y0+SHIFT}, {{}, 0}});
	int ans = 0;
	while(!q.empty()) {
		auto [p, pp] = q.front();
		auto [used, points] = pp;
		ans = max(points, ans);
		q.pop();
		ins(p, {p.x+1, p.y+1}, {p.x+2, p.y+2}, used, points);
		ins(p, {p.x-1, p.y+1}, {p.x-2, p.y+2}, used, points);
		ins(p, {p.x+1, p.y-1}, {p.x+2, p.y-2}, used, points);
		ins(p, {p.x-1, p.y-1}, {p.x-2, p.y-2}, used, points);
	}
	cout << ans << '\n';


	return 0;
}
