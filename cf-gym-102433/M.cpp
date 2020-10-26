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
const int N = 2050;

int n, m;
int new_n;
char mat[N][N];
vi start_col(N, N-5), end_col(N);
vi start_line(N, N-5);
int comp[N][N];

void read_rotate(bool prt = false) {
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			mat[i][j] = ' ';

	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		string line;
		cin >> line;
		for(int j = 1; j <= m; j++) {
			int new_line = i-j+m;
			int new_j = i+j;
			start_col[new_line] = min(start_col[new_line], new_j);
			end_col[new_line] = max(end_col[new_line], new_j);
			// start_line[new_j] = min(start_col[new_line], new_line);
			// if(prt)
			// 	cout << "(" << i << ", " << j << ") = " << new_line << ' ' << new_j << '\n';
			char c;
			if(line[j-1] == '/')
				c = '|';
			else if(line[j-1] == '\\')
				c = '-';
			else
				c = '#';
			mat[new_line][new_j] = c;
			if(c == '-' and new_j >= 2 and mat[new_line][new_j-2] == '-')
				mat[new_line][new_j-1] = '-';
			else if(c == '|' and new_line >= 2 and mat[new_line-2][new_j] == '|')
				mat[new_line-1][new_j] = '|';
			if(mat[new_line][new_j-1] == ' ' and (c == '#' or c == '|' or c == '-') and new_j >= 2 and (mat[new_line][new_j-2] == '|' or mat[new_line][new_j-2] == '#' or mat[new_line][new_j-2] == '-'))
				mat[new_line][new_j-1] = '#';
			// if(c == '|' and new_j >= 2 and (mat[new_line][new_j-2] == '|' or mat[new_line][new_j-2] == '#'))
			// 	mat[new_line][new_j-1] = '#';
			// if((c == '|' or c == '.') and new_j >= 2 and mat[new_line][new_j-2] != '-')
			// 	mat[new_line][new_j-1] = '.';
		}
	}
	for(int i = 0; i < N; i++) {
		start_col[i] = max(0, start_col[i]-5);
		end_col[i] = min(N-5, end_col[i]+5);
	}
	for(int i = 0; i < N; i++) {
		if(i != 0 and i != n+m) {
		for(int j = 0; j < start_col[i]; j++)
			mat[i][j] = '|';
		for(int j = end_col[i]; j < N; j++)
			mat[i][j] = '|';
		}
	}

	new_n = (n+m)+10;
	new_n = N-5;
	for(int i = 0; i <= new_n; i++)
		for(int j = 0; j <= new_n; j++) {
			if(j>1)
				assert(!(mat[i][j] != ' ' and mat[i][j-2] != ' ' and mat[i][j-1] == ' '));
			if(prt)
				cout << mat[i][j] << "\0\n"[j==new_n];
		}
}

bitset<N> comp_vis;
// int runs;

void dfs(int x, int y, int cur_comp) {
	// cout << ++runs << '\n';
	// cout.flush();
	if(mat[x][y] == '|' or mat[x][y] == '-') return;
	if(comp[x][y]) return;
	// cout << "(" << x << ", " << y << ") " << cur_comp << '\n';
	comp[x][y] = cur_comp;
	if(y)
		dfs(x, y-1, cur_comp);
	if(x)
		dfs(x-1, y, cur_comp);
	if(y < new_n)
		dfs(x, y+1, cur_comp);
	if(x < new_n)
		dfs(x+1, y, cur_comp);
}

int solve() {
	int ans = 0;
	int cur_comp = 0;
	// vi adj[N];
	for(int i = 0; i < new_n; i++)
		for(int j = 0; j < new_n; j++)
			if(!comp[i][j] and mat[i][j] != '|' and mat[i][j] != '-') {
				if(DBG) {
					cout << "comp: (" << i << ", " << j << ") " << cur_comp << '\n';
					// cout << "mat = " << mat[i][j] << 
				}
				dfs(i, j, ++cur_comp);
			}
	// for(int i = 0; i < N; i++)
	// 	for(int j = 0; j < N; j++) {
	// 		if(mat[i][j] == '-') {
	// 			if(mat[i-1][j] == '#' and mat[i+1][j] == '#'
	// 					and comp[i+1][j] != comp[i-1][j]) {
	// 				adj[comp[i-1][j]].push_back(comp[i+1][j]);
	// 				adj[comp[i+1][j]].push_back(comp[i-1][j]);
	// 			}
	// 		} else if(mat[i][j] == '|') {
	// 			if(mat[i][j-1] == '#' and mat[i][j+1] == '#'
	// 					and comp[i][j+1] != comp[i][j-1]) {
	// 				adj[comp[i][j-1]].push_back(comp[i][j+1]);
	// 				adj[comp[i][j+1]].push_back(comp[i][j-1]);
	// 			}
	// 		}
	// 	}
	// comp_vis[1] = 1;
	// int n_comp = cur_comp-1;
	return cur_comp-1;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	read_rotate(DBG);
	
	cout << solve() << '\n';


	return 0;
}
