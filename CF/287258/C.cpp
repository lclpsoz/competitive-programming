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

const int N = 5e5 + 10, ALPHA = 26;
const char BASE = 'a';
int trie[N][ALPHA], cnt;
bool terminal[N];
int mn[N], mx[N], pos[N], id[N];

void insert(const string& s, int i)
{
	int cur = 0;
	for(char ch : s)
	{
		int c = ch - BASE;
		if(trie[cur][c] == -1)
			trie[cur][c] = ++cnt, terminal[cnt] = false, id[cnt] = -1;
		cur = trie[cur][c];
	}
	terminal[cur] = true;
	id[cur] = i;
}

int k;
void dfs(int cur)
{
	if(!terminal[cur])
		mx[cur] = -1, mn[cur] = INF<int>;
	else
		mx[cur] = mn[cur] = pos[id[cur]] = k++;

	for(char ch = 'a'; ch <= 'z'; ch++)
	{
		int c = ch - BASE;
		if(trie[cur][c] != -1)
		{
			dfs(trie[cur][c]);
			mn[cur] = min(mn[cur], mn[trie[cur][c]]);
			mx[cur] = max(mx[cur], mx[trie[cur][c]]);
		}
	}
}

// const int M = 1e5 + 10;
// string s[M];

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int tt; cin >> tt;
	while(tt--)
	{
		k = 0;
		cnt = 0;
		memset(trie, -1, sizeof trie);

		int n; cin >> n;
		vector<string> s(n);
		for(int i = 0; i < n; i++)
		{
			cin >> s[i];
			insert(s[i], i);
		}

		dfs(0);

		for(int i = 0; i < n; i++)
		{
			int ans = LEN(s[i]) + 1;
			int cur = 0;
			for(int j = 0; j < LEN(s[i]); j++)
			{
				int now = j + 1 + min({pos[i] - mn[cur], 1 + mx[cur] - pos[i]});
				ans = min(ans, now);
				cur = trie[cur][s[i][j] - BASE];
			}

			cout << ans << " \n"[i == n - 1];
		}
	}

	return 0;
}
