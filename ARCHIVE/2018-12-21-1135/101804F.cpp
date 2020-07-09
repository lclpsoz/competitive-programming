#include <bits/stdc++.h>
using namespace std;

#define len(x) (int)x.size()
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

const int MOD = 1000'000'007;
const double EPS = 0.000'000'001;

inline int fcmp(double x, double y)
{ return (x < y + EPS ? (x < y - EPS ? -1 : 0) : 1);}

const int N = 1'000'10;
const int M = 1'000'10;

bool vis[N];
int dp[N][2];
vi g[N];

int dfs(int v, int p, bool j)
{
	vis[v] = true;
	if(dp[v][j] != -1) return dp[v][j];
	
	int a1 = j;
	
	for(int& u : g[v])
	{
		if(!vis[u])
		{
			if(!j)
				a1 += max(dfs(u, v, 0), dfs(u, v, 1));
			else
				a1 += dfs(u, v, 0);
		}
	}
	
	vis[v] = false;
	return dp[v][j] = a1;
}

int main()
{
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	ios_base::sync_with_stdio(false);
	cout.precision(10);
	
	int n, m;
	cin >> n >> m;
	
	for(int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		
		g[a].emplace_back(b);		
		g[b].emplace_back(a);		
	}
	
	memset(dp, -1, sizeof(dp));
	
	int x = dfs(1, 0, 0);
	memset (vis, 0, sizeof vis);
	int y = dfs(1, 0, 1);
	
	cout << max(x, y) << endl;
	
	// for(int i = 1; i <= n; i++)
	// 	cout << dp[i][0] << "/" << dp[i][1] << endl;
	
	//cerr << "Tempo de execucao: " << (double)clock() / CLOCKS_PER_SEC << endl;
	return 0;
}
