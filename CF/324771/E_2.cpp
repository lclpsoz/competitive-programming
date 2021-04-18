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
const T INF = (is_same<T, int>::value ? 1e9 : 4e18);
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

const int N = 1e5 + 10;

int n, m;
int t[N];
bitset<N> can_divide;
bitset<N> not_prime;
vi primes;

void fill_can_divide () {
	map<int, int> mp;
	for (int i = 1; i <= n; i++)
		mp[t[i]]++;
	
	vi vals;
	for (int i = 1; i <= n; i++)
		vals.push_back(t[i]);
	sort(ALL(vals));
	vals.resize(unique(ALL(vals)) - vals.begin());
	set<int> v_div;
	for (int v : vals) {
		for (ll i = 2*v; i <= vals.back();) {
			int nxt_val = *lower_bound(ALL(vals), i);
			if (nxt_val == i) {
				v_div.insert(v);;
				break;
			}
			i = (nxt_val/v + 1)*1LL*v;
		}
	}
	for (int i = 1; i <= n; i++)
		if (mp[t[i]] > 1 or v_div.count(t[i]))
			can_divide[i] = true;
}

// What if 10**13 with N = 1e5
vpii factorization (int v) {
	vpii ret;
	for (int p : primes) {
		if (p*1LL*p > v) break;
		if (v%p == 0) {
			if (!LEN(ret) or ret.back().x != p)
				ret.push_back({p, 0});
			while (v%p == 0)
				ret.back().y++, v/=p;
		}
	}
	if (v > 1)
		ret.push_back({v, 1});

	return ret;
}

void impossible () {
	for (int i = 1; i <= n; i++)
		cout << "Never\n";
	exit(0);
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	// Sieve
	for (int i = 2; i*i < N; i++)
		if (!not_prime[i])
			for (int j = i*i; j < N; j+=i)
				not_prime[j] = 1;
	for (int i = 2; i*i <= INF<int>; i++)
		if (!not_prime[i])
			primes.push_back(i);

	// cerr << LEN(primes) << '\n';

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> t[i];
	fill_can_divide();

	// Unique primes
	vi used_primes;
	vector<vpii> facts(n+1);
	for (int i = 1; i <= n; i++) {
		facts[i] = factorization(t[i]);
		for (auto [p, pt] : facts[i])
			used_primes.push_back(p);
	}
	sort(ALL(used_primes));
	used_primes.resize(unique(ALL(used_primes)) - used_primes.begin());
	auto pos_prime = [&](int val) {
		return lower_bound(ALL(used_primes), val) - used_primes.begin();
	};

	// Max expoents
	vpii maxis(LEN(used_primes)+1);
	for (int i = 1; i <= n; i++) {
		vpii &fact = facts[i];
		for (auto [p, pt] : fact) {
			int pos = pos_prime(p);
			pii &now = maxis[pos];
			if (pt > now.y) {
				now.x = now.y;
				now.y = pt;
			}
			else
				now.x = max(now.x, pt);
		}
	}

	// Solve
	ll lcm_all = 1;
	for (auto p : used_primes) {
		int pos = pos_prime(p);
		int expo = maxis[pos].y;
		while (expo and lcm_all < INF<ll>/p)
			lcm_all *= p, expo--;
		if (expo)
			impossible();
	}
	// for (int i = 0; i < LEN(used_primes); i++)
	// 	cerr << "i = " << i << ", used_p = " << used_primes[i] << ", maxis = {" << maxis[i].x << ' ' << maxis[i].y << "}\n";
	// cerr << "lcm_all = " << lcm_all << '\n';

	// Answer
	for (int i = 1; i <= n; i++) {
		// cerr << "i = " << i << ": ";
		if (can_divide[i])
			cout << "Never\n";
		else {
			ll now = lcm_all;
			for (auto [p, pt] : facts[i]) {
				int pos = pos_prime(p);
				// cerr << "p = " << p << ", pt = " << pt << ", pos = " << pos << '\n';
				assert(maxis[pos].y >= pt);
				if (maxis[pos].y == pt) {
					int delta = pt - maxis[pos].x;
					while (delta)
						now /= p, --delta;
				}
			}
			// cerr << "now = " << now << '\n';
			ll ori_now = now;
			now = (m/now)*now;
			while (now < m or (now-m <= INF<int> and now%t[i] == 0))
				now += ori_now;

			if (now%t[i] == 0)
				cout << "Never\n";
			else if (now-m > INF<int>)
				cout << "Never\n";
			else
				cout << now-m << '\n';
		}
	}

	return 0;
}
