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

const int DBG = 0;
const int ST = 10;
const int N = 2e3;

int comp[N][N];
char mat[N][N];
set<int> adj[N*N];

void comp_dfs(int x, int y, int comp_now) {
	if(comp[x][y] or mat[x][y] == '#') return;
	if(DBG)
		cout << "comp_now = " << comp_now << ", pos = " << x << ", " << y << '\n';
	comp[x][y] = comp_now;
	comp_dfs(x+1, y, comp_now);
	comp_dfs(x-1, y, comp_now);
	comp_dfs(x, y+1, comp_now);
	comp_dfs(x, y-1, comp_now); 
}

void check_adj(int x, int y) {
	int comp_now = comp[x][y];
	// for(int i = x-3; i <= x+3; i+=6)
	// 	for(int j = y-2; j <= y+2; j++) {
	// 		if(comp[i][j] != comp_now)
	// 			adj[comp_now].insert(comp[i][j]);
	// 		if(comp[j][i] != comp_now)
	// 			adj[comp_now].insert(comp[j][i]);
	// 	}
	for(int i = x-2; i <= x+2; i++)
		for(int j = y-2; j <= y+2; j++)
			if(comp[i][j] and comp[i][j] != comp_now)
				adj[comp_now].insert(comp[i][j]);
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
	
	int n, m;
	pii st;
	pii en;
	cin >> n >> m;
	cin >> st.x >> st.y;
	cin >> en.x >> en.y;
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			mat[i][j] = '#';
	for(int i = ST; i < ST+n; i++) {
		string s;
		cin >> s;
		for(int j = 0; j < m; j++)
			mat[i][ST+j] = s[j];
	}

	int comp_now = 1;
	for(int i = ST; i < ST+n; i++)
		for(int j = ST; j < ST+m; j++)
			if(comp[i][j] == 0 and mat[i][j] == '.')
				comp_dfs(i, j, comp_now++);

	int v_st = comp[st.x+ST-1][st.y+ST-1];
	int v_en = comp[en.x+ST-1][en.y+ST-1];
	if(v_st == v_en)
		cout << "0\n";
	else {
		for(int i = ST; i < ST+n; i++)
			for(int j = ST; j < ST+m; j++)
				if(comp[i][j])
					check_adj(i, j);
		
		queue<pii> q;
		q.push({v_st, 0});
		bitset<N*N> vis; 
		while(!q.empty() and q.front().x != v_en) {
			auto [v, dist] = q.front();
			q.pop();
			if(vis[v]) continue;
			vis[v] = 1;
			for(int u : adj[v])
				q.push({u, dist+1});
		}
		if(q.empty())
			cout << "-1\n";
		else
			cout << q.front().y << '\n';
	}
	

	return 0;
}
