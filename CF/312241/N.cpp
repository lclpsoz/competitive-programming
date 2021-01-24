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
	int ret = x%m;
	if (ret < 0)
		ret += m;
	return ret;
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

const int N = 5e3 + 10, M = 105;
int dp[M][N], mn[M][N];
int d, b, m, p[M];

template<class base_t, class func = function<base_t(const base_t&, const base_t&)>>
class mqueue
{
private:
	vector<pair<base_t, base_t>> s1, s2;
	func f;

	void move()
	{
		while(!s2.empty())
		{
			base_t x = s2.back().first;
			s2.pop_back();
			
			if(s1.empty()) s1.emplace_back(x, x);
			else s1.emplace_back(x, f(x, s1.back().second));
		}
	}

public:
	mqueue(const func& _f) { f = _f;}
	
	void pop() { if(s1.empty()) move(); s1.pop_back();}
	void push(base_t x)
	{
		if(s2.empty()) s2.emplace_back(x, x);
		else s2.emplace_back(x, f(x, s2.back().second));
	}
	
	base_t front() { if(s1.empty()) move(); return s1.back().first;}	
	base_t get()
	{
		if(!s1.empty() && !s2.empty())
			return f(s1.back().second, s2.back().second);
		else if(!s1.empty())
			return s1.back().second;
		else
			return s2.back().second;
	}
	
	int size() { return LEN(s1) + LEN(s2);}
	bool empty() { return size() == 0;}
	void clear() { s1.clear(); s2.clear();}
};

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	cin >> d >> b >> m;
	for(int i = 1; i <= m; i++) cin >> p[i];
	sort(p + 1, p + m + 1);

	int l = 1, r = d, ans = 0;
	while(l <= r)
	{
		int mid = (l + r) / 2;
		int best = INF<int>;

		dp[0][0] = 0;
		for(int j = 1; j <= d; j++) dp[0][j] = INF<int>;
		vector<mqueue<int>> v;	
		for(int i = 1; i <= m; i++)
		{
			v.emplace_back([&](int x, int y){ return min(x, y);});
			for(int j = 0; j <= d; j++)
			{
				v[i - 1].push(dp[i - 1][j]);
				if(LEN(v[i - 1]) > mid + 1) v[i - 1].pop();

				int& now = dp[i][j];
				now = dp[i - 1][j];
				now = min(now, abs(p[i] - j) + v[i - 1].get());
				
				if(j + mid >= d)
 					best = min(best, now);
			}
		}

		if(best <= b)
			r = mid - 1, ans = mid;
		else
			l = mid + 1;
	}

	cout << ans << endl;

	return 0;
}
