#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

#define LEN(x) (int)x.size()
#define ALL(x) x.begin(), x.end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;
using vpii = vector<pii>;

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

template<typename T>
const T INF = (is_same<T, int>::value ? 1e9 : 1e18);
const int MOD = 1e9 + 7;
const double EPS = 1e-9;

inline int fcmp(double x, double y)
{ return (x < y + EPS ? (x < y - EPS ? -1 : 0) : 1);}

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

    hash_t substr(int p, int sz, int diff = 0)
    {
        while(LEN(_pow) <= diff)
            _pow.emplace_back(_pow.back() * BASE);
        return (val[p + sz] - val[p]) * _pow[diff];
    }
};

const int N = 710;
int dp[N][N];
int n;
string s;
shash hs;
int pre[N][N];

int solve(int l, int r)
{
	if(l > r) return 0;
	
	int& ans = dp[l][r];

	if(ans == -1)
	{
		ans = r - l + 1;

		for(int i = l; i <= r; i++)
			ans = min(ans, solve(l, i) + solve(i + 1, r));

		if(pre[l][r] != r - l + 1)
			ans = min(ans, solve(l, l + pre[l][r] - 1));
	}
	
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);
	
	cin >> n >> s;
	hs = shash(s);

	for(int l = 0; l < n; l++)
		for(int r = l; r < n; r++)
		{
			pre[l][r] = r - l + 1;
			for(int k = 1; k <= r - l + 1; k++)
				if(hs.substr(l, pre[l][r - k], r - k + 1 - l) == hs.substr(r - k + 1, k))
					pre[l][r] = k;
		}


	memset(dp, -1, sizeof dp);
	cout << solve(0, n - 1) << endl;

	return 0;
}