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

using hash_t = pair<int, int>;
const hash_t MODS = {1000000007, 982451653};
hash_t BASE = {313, 541};
vector<hash_t> _pow = {hash_t(1, 1)};

void gen_base()
{
	auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	std::mt19937 mt_rand(seed);
	int base1 = std::uniform_int_distribution<int>(300, MODS.first - 4)(mt_rand) | 1;
	int base2 = std::uniform_int_distribution<int>(300, MODS.second - 4)(mt_rand) | 1;
	if(base1 == base2)
		base2 += 2;
	BASE = {base1, base2};
}

inline hash_t operator * (const hash_t& a, const hash_t& b)
{
	return {int((a.first * 1LL * b.first) % MODS.first), int((a.second * 1LL * b.second) % MODS.second)};
}
inline hash_t operator * (const hash_t& a, const int b)
{
	return {int((a.first * 1LL * b) % MODS.first), int((a.second * 1LL * b) % MODS.second)};
}
inline hash_t operator + (const hash_t& a, const hash_t& b)
{
	return {(a.first + b.first) % MODS.first, (a.second + b.second) % MODS.second};
}
inline hash_t operator - (const hash_t& a, const hash_t& b)
{
	return {(a.first - b.first + MODS.first) % MODS.first, (a.second - b.second + MODS.second) % MODS.second};
}

struct shash
{
	int n;
	vector<hash_t> val;

	shash(const shash& o)
	{
		n = o.n;
		val = o.val;
	}

	shash(const string& _s = "")
	{
		n = 0;
		val = {hash_t(0, 0)};
		for(char c : _s)
			push_back(c);
	}

	void push_back(char c)
	{
		n++;
		while(LEN(_pow) < n)
			_pow.emplace_back(_pow.back() * BASE);
		val.emplace_back(val.back() + _pow[n - 1] * c);
	}

	void pop_back()
	{
		n--;
		val.pop_back();
	}

	hash_t substr(int p, int sz, int diff)
	{
		return (val[p + sz] - val[p]) * _pow[diff];
	}

};

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int tt; cin >> tt;
	while(tt--)
	{
		int n; cin >> n;
		vector<string> s(n);
		vector<shash> hs(n);
		for(int i = 0; i < n; i++)
		{
			cin >> s[i];
			hs[i] = shash(s[i]);
		}
		vi p(n), pos(n);
		iota(ALL(p), 0);

		auto cmp = [&](int i, int j)
		{
			int l = 0, r = min(LEN(s[i]), LEN(s[j])), k = 0;
			while(l <= r)
			{
				int mid = (l + r) / 2;
				if(hs[i].substr(0, mid, 0) == hs[j].substr(0, mid, 0))
					l = mid + 1, k = mid;
				else
					r = mid - 1;
			}

			if(k == min(LEN(s[i]), LEN(s[j])))
				return LEN(s[i]) < LEN(s[j]);
			else return s[i][k] < s[j][k];
		};

		sort(ALL(p), cmp);

		for(int i = 0; i < n; i++)
			pos[p[i]] = i;

		for(int i = 0; i < n; i++)
		{
			int ans = LEN(s[i]) + 1;
			int x = 0, y = n - 1;
			for(int j = 0; j < LEN(s[i]); j++)
			{
				int now = j + 1 + min({pos[i] - x, 1 + y - pos[i]});
				ans = min(ans, now);

				{
					int l = x, r = y, it = x;
					while(l <= r)
					{
						int mid = (l + r) / 2;
						if()
					}
				}
			}

			cout << ans << " \n"[i == n - 1];
		}
	}

	return 0;
}
