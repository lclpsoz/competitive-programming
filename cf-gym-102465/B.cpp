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
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int n; cin >> n;

	mqueue<int> ql([&](int i, int j){ return max(i, j);});
	mqueue<int> qr([&](int i, int j){ return min(i, j);});

	int ans = 0;
	queue<pii> q;

	for(int i = 0; i < n; i++)
	{
		int l, r;
		cin >> l >> r;

		if(empty(q))
		{
			q.emplace(l, r);
			ql.push(l);
			qr.push(r);
		}
		else
		{
			int x = ql.get();
			int y = qr.get();

			if(l > y || r < x)
			{
				while(!empty(q)) q.pop();
				ql.clear(), qr.clear();

				q.emplace(l, r);
				ql.push(l);
				qr.push(r);
			}
			else
			{
				q.emplace(l, r);
				ql.push(l);
				qr.push(r);

				while(LEN(q) > qr.get() - ql.get() + 1)
				{
					q.pop();
					ql.pop();
					qr.pop();
				}
			}
		}

		int x = ql.get();
		int y = qr.get();

		ans = max(ans, min(LEN(q), y - x + 1));
	}

	cout << ans << endl;

	return 0;
}
