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

const int N = 2e3 + 10;
char grid[N][N];
int tU[N][N], tR[N][N], tD[N][N], tL[N][N];
pii p[N][N];
bool vis[N][N];

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

    int n, m;
    cin >> n >> m;

    pii s, e;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') s = {i, j}, grid[i][j] = '.';
            if (grid[i][j] == 'E') e = {i, j}, grid[i][j] = '.';
        }
    }

    for (int i = 1; i <= n; i++)
	{
		int lst = 0;
		for(int j = 1; j <= m; j++)
			if(grid[i][j] == '.')
				tL[i][j] = lst, lst = j;
		lst = 0;
		for(int j = m; j > 0; j--)
			if(grid[i][j] == '.')
				tR[i][j] = lst, lst = j;
	}  
    
	for(int j = 1; j <= m; j++)
	{
		int lst = 0;
		for (int i = 1; i <= n; i++)
			if(grid[i][j] == '.')
				tU[i][j] = lst, lst = i;
		lst = 0;
		for (int i = n; i > 0; i--)
			if(grid[i][j] == '.')
				tD[i][j] = lst, lst = i;
	}  

    queue<pii> q;
    vis[s.first][s.second] = 1;
    q.push(s);

    while (!q.empty()) {
		auto[x, y] = q.front();
		q.pop();

		// cout << x << " " << y << endl;

		if(pii(x, y) == e)
		{
			string ans;

			// cout << "(" << x << ", " << y << ")";
			while(pii(x, y) != s)
			{
				if(p[x][y].first == x)
				{
					if(p[x][y].second > y)
						ans.push_back('L');
					else
						ans.push_back('R');
				}
				else
				{
					if(p[x][y].first > x)
						ans.push_back('U');
					else
						ans.push_back('D');
				}
				tie(x, y) = p[x][y];
				// cout << " <- (" << x << ", " << y << ")";
			}

			reverse(ALL(ans));
			cout << LEN(ans) << endl << ans << endl;

			return 0;
		}
       
        if(x + 1 <= n && !vis[x + 1][y] && grid[x + 1][y] == '.')
		{
			p[x + 1][y] = {x, y};
			vis[x + 1][y] = true;
			q.push({x + 1, y});
		}
        if(tD[x][y] && !vis[tD[x][y]][y])
		{
			p[tD[x][y]][y] = {x, y};
			vis[tD[x][y]][y] = true;
			q.push({tD[x][y], y});
		}
        if(y - 1 > 0 && !vis[x][y - 1] && grid[x][y - 1] == '.')
		{
			p[x][y - 1] = {x, y};
			vis[x][y - 1] = true;
			q.push({x, y - 1});
		}
        if(tL[x][y] && !vis[x][tL[x][y]])
		{
			p[x][tL[x][y]] = {x, y};
			vis[x][tL[x][y]] = true;
			q.push({x, tL[x][y]});
		}
        if(y + 1 <= m && !vis[x][y + 1] && grid[x][y + 1] == '.')
		{
			p[x][y + 1] = {x, y};
			vis[x][y + 1] = true;
			q.push({x, y + 1});
		}
        if(tR[x][y] && !vis[x][tR[x][y]])
		{
			p[x][tR[x][y]] = {x, y};
			vis[x][tR[x][y]] = true;
			q.push({x, tR[x][y]});
		}
        if(x - 1 > 0 && !vis[x - 1][y] && grid[x - 1][y] == '.')
		{
			p[x - 1][y] = {x, y};
			vis[x - 1][y] = true;
			q.push({x - 1, y});
		}
        if(tU[x][y] && !vis[tU[x][y]][y])
		{
			p[tU[x][y]][y] = {x, y};
			vis[tU[x][y]][y] = true;
			q.push({tU[x][y], y});
		}
    }

	cout << -1 << endl;

	return 0;
}
