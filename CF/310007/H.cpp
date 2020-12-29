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

template <class base_t>
struct fenwick
{
	vector<base_t> t;
	int n;

	fenwick(int _n = 0) : n(_n)
	{
		t.assign(n + 1, 0);
	}

	void add(int p, base_t v)
	{
		for(int i = p; i <= n; i += i & -i)
			t[i] += v;
	}

	base_t sum(int p)
	{
		base_t ans = 0;
		for(int i = p; i > 0; i -= i & -i)
			ans += t[i];
		return ans;
	}

	base_t sum(int l, int r)
	{
		return sum(r) - sum(l - 1);
	}
};

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int t; cin >> t;
	while(t--)
	{
		int n, k, m;
		cin >> n >> k >> m;

		vi x(n, false);
		for(int i = 0; i < m; i++)
		{
			int b; cin >> b;
			x[--b] = true;
		}

		if((n - m) % (k - 1))
		{
			cout << "NO" << endl;
			continue;
		}

		vi s;
		int cnt = 0;
		for(int i = 0; i < n; i++)
		{
			if(!x[i]) cnt++;
			else 
			{
				if(cnt) s.emplace_back(cnt);
				s.emplace_back(0);
				cnt = 0;
			}
		}

		if(cnt) s.emplace_back(cnt), cnt = 0;

		for(int& i : s)
			i -= (k - 1) * ((i - 1) / (k - 1));

		while(!empty(s) && s.back() == 0) s.pop_back();
		reverse(ALL(s));
		while(!empty(s) && s.back() == 0) s.pop_back();
		reverse(ALL(s));

		x.clear();
		for(int& i : s)
		{
			if(!i){ if(!x.back()) x.emplace_back(true);}
			else
				for(int j = 0; j < i; j++) x.emplace_back(false);
		}

		n = LEN(x);
		m = 0;
		for(int i = 0; i < n; i++)
		{
			if(x[i]) m++;
			cout << i + 1 << "(" << x[i] << ")" << " \n"[i == n - 1];
		}

		if((n - m) % (k - 1))
		{
			cout << "NO" << endl;
			continue;
		}

		fenwick<int> bit(n + 10);
		for(int i = 0; i < n; i++) bit.add(i + 1, 1);

		int d = (n - m) / (k - 1);
		bool ok = true;
		int l = 0, r = n - 1;
		vector<bool> y(n, false);
		for(int z = 0; z < d && ok; z++)
		{
			vi a, b;
			while(LEN(a) < k / 2 && ok)
			{
				while(l < n && (x[l] || y[l])) l++;
				if(l == n) ok = false;
				else a.emplace_back(l), y[l] = true;
			}
			while(LEN(b) < k / 2 && ok)
			{
				while(r >= 0 && (x[r] || y[r])) r--;
				if(r == -1) ok = false;
				else b.emplace_back(r), y[r] = true;
			}

			if(l + 1 > r - 1 || bit.sum(l + 1, r - 1) == 0) ok = false;

			if(ok)
			{
				for(int i : a) bit.add(i + 1, -1);//, cout << i + 1 << " ";
				for(int i : b) bit.add(i + 1, -1);//, cout << i + 1 << " ";
				// cout << endl;
			}
			
		}

		cout << (ok ? "YES" : "NO") << endl;
	}

	return 0;
}
