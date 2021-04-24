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

    int size()
    {
        return n;
    }
};

int main () {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);
	
	gen_base();

	int n; 
	while(cin >> n)
	{
		vector<string> vs(n);
		vector<hash_t> hs(n);
		map<hash_t, int> mp;
		vector<vector<char>> cc(10);
		for(int i = 0; i < n; i++)
		{
			cin >> vs[i];
			hs[i] = shash(vs[i]).substr(0, LEN(vs[i]), 0);
			mp[hs[i]] = i;
			for(int j = 0; j < LEN(vs[i]); j++)
				cc[j].emplace_back(vs[i][j]);
		}

		for(int j = 0; j < LEN(vs[0]); j++)
		{
			sort(ALL(cc[j]));
			cc[j].resize(int(unique(ALL(cc[j])) - cc[j].begin()));
		}

		vector<int> q;
		vi par(n, -1), dist(n, -1);
		q.emplace_back(0);
		dist[0] = 0;

		bool ok = false;
		for(int i = 0; i < LEN(q) && !ok; i++)
		{
			int id = q[i];
			hash_t hnow = hs[id];

			for(int p = 0; p < LEN(vs[id]) && !ok; p++)
				for(char c : cc[p])
					if(c != vs[id][p])
					{
						// cout << "before: " << hnow.first << " -> ";
						hnow = hnow - _pow[p] * vs[id][p];
						hnow = hnow + _pow[p] * c;
						if(mp.count(hnow))
						{
							int id2 = mp[hnow];
							if(dist[id2] == -1)
							{
								// cout << vs[id] << " -> " << vs[id2] << endl;
								par[id2] = id;
								dist[id2] = dist[id] + 1;
								q.emplace_back(id2);

								if(id2 == n - 1)
									ok = true;
							}
						}
						hnow = hnow - _pow[p] * c;
						hnow = hnow + _pow[p] * vs[id][p];
						// cout << "after: " << hnow.first << endl;
					}
		}

		if(!ok)
			cout << "FAIL\n";
		else
		{
			int i = n - 1;
			cout << dist[i] + 1 << endl;
			vector<int> ans;
			while(i >= 0)
			{
				ans.emplace_back(i);
				i = par[i];
			}
			reverse(ALL(ans));
			for(int t : ans) cout << vs[t] << '\n';
		}
	}

	return 0;
}
