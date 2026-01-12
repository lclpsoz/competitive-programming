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

int n, m;
int mp[5050][5050];
bool vis[5050];
vpii edges;
vector<vector<int>> cls;

pair<int, bool> dfs (int now, int end, int cur_min) {
    if (vis[now]) return {0, false};
    vis[now] = 1;

    if (mp[now][end] != -1) {
        pair<int, bool> p = {0, true};
        if (!mp[now][end] or mp[now][end] == cur_min)
            mp[now][end] = mp[end][now] = cur_min, p.x = 1;
        return p;

    }

    // cout << "  now = " << now << " | end = " << end << " | cur_min = " << cur_min << endl;
    pair<int, bool> ret = {0, false};
    for (int j = 0; j < LEN(cls[now]); j++) {
        int node = cls[now][j];

        pair<int, bool> now_dfs = dfs(node, end, cur_min);
        ret.x += now_dfs.x;
        ret.y = ret.y or now_dfs.y;
        if (ret.y) {
            if (!mp[now][node] or mp[now][node] == cur_min) {
                mp[now][node] = mp[node][now] = cur_min;
                ret.x++;
            }
            break;
        }
    }

    return ret;
}


int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cls.push_back(vector<int>());
        for (int j = 1; j <= n; j++)
            mp[i][j] = -1;
    }
    cls.push_back(vector<int>());

    for (int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        mp[x][y] = 0;
        mp[y][x] = 0;
        edges.push_back({x, y});
        cls[x].push_back(y);
        cls[y].push_back(x);
    }

    cin >> m;
    vector<pair<int, pii>> customers;
    for (int i = 0; i < m; i++) {
        int x, y, g;
        cin >> x >> y >> g;

        customers.push_back({-g, {x, y}});
    }
    sort(ALL(customers));

    for (int i = 0; i < m; i++) {
        for (int j = 1; j <= n; j++) vis[j] = 0;
        int x, y, cur_min;
        pair<int, pii> now = customers[i];
        cur_min = -now.x;
        x = now.y.x;
        y = now.y.y;

        pair<int, bool> graph = dfs(x, y, cur_min);
        // cout << " customer " << x << ' ' << y << " graph = " << graph.x << ' ' << graph.y << endl;
        if (!graph.x) {
            cout << -1 << endl;
            return 0;
        }
    }

    /* cout << "MP:" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j<= n; j++)
            cout << mp[i][j] << ' ';
        cout << endl;
    }
        */

    for (int i = 0; i < n-1; i++) {
        int x = edges[i].x, y = edges[i].y;
        if (!mp[x][y]) mp[x][y] = 1;
        if (i) cout << ' ';
        cout << mp[x][y];
    }
    cout << endl;

	return 0;
}
