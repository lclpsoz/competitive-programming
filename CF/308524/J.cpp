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

const int N = 14, M = 1 << 15;
bool w[M], vis[M];
char mp[26][26];
string s[M];

bool is_vowel(char c)
{
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; 
}

string run(bool k, int msk)
{
	string ans;
	if(k)
	{
		for(int i = 0; i < LEN(s[msk]); i += 2)
			if(i + 1 < LEN(s[msk]))
				ans.push_back(mp[int(s[msk][i] - 'a')][int(s[msk][i + 1] - 'a')]);
			else
				ans.push_back(s[msk][i]);
	}
	else
	{
		for(int i = LEN(s[msk]) - 1; i >= 0; i -= 2)
			if(i)
				ans.push_back(mp[int(s[msk][i - 1] - 'a')][int(s[msk][i] - 'a')]);
			else
				ans.push_back(s[msk][i]);
		reverse(ALL(ans));
	}

	return ans;
}

bool solve(int msk)
{
	if(vis[msk]) return w[msk];
	int lg = 31 - __builtin_clz(msk);
	int lg1 = lg + 1;
	int l = (msk | (1 << lg1)) ^ (1 << lg), r = msk | (1 << lg1);
	if(lg % 2) w[msk] = min(solve(l), solve(r));
	else w[msk] = max(solve(l), solve(r));
	return w[msk];
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int t; cin >> t;
	while(t--)
	{
		for(int i = 0; i < 26; i++)
			for(int j = 0; j < 26; j++)
				cin >> mp[i][j];
		cin >> s[1];
		// cout << run(0, 1) << endl;
		// cout << run(1, 1) << endl;
		// cout << "aa: " << mp[0][0] << ", ca: " << mp[2][0] << ", ac: " << mp[0][2] << endl;
		// cout << "ed: " << mp[4][3] << ", de: " << mp[3][4] << endl;
		for(int msk = 2; msk < M; msk++)
		{
			int lg = 31 - __builtin_clz(msk);
			int lg1 = lg - 1;
			int old = (msk | (1 << lg1)) ^ (1 << lg);
			if(LEN(s[old]) <= 1) break;
			bool k = msk & (1 << lg1);
			s[msk] = run(k, old);
			vis[msk] = false;
			if(LEN(s[msk]) == 1)
			{
				w[msk] = is_vowel(s[msk][0]);
				vis[msk] = true;
			}
			// cout << bitset<3>(msk) << ": " << s[msk] << endl;
		}

		cout << (solve(1) ? "Salah" : "Marzo") << endl;
	}

	return 0;
}
