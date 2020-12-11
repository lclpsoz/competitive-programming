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

vi prefix_function(const string& s)
{
	int n = LEN(s);
	vi pi(n, 0);
	for(int i = 1, j = 0; i < n; i++)
	{
		while(j > 0 && s[i] != s[j]) j = pi[j - 1];
		if(s[i] == s[j]) j++;
		pi[i] = j;
	}
	return pi;
}

vi kmp(const string& s, const string& t)
{
	int n = LEN(s), m = LEN(t);
	vi pi = prefix_function(s);
	vi matches;
	for(int i = 0, j = 0; i < m; i++)
	{
		while(j > 0 && t[i] != s[j]) j = pi[j - 1];
		if(t[i] == s[j]) j++;
		if(j == n)
			matches.emplace_back(i), j = pi[j - 1];
	}
	return matches;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
	
	int tt; cin >> tt;
	while(tt--)
	{
		int n; cin >> n;
		string a, b, s, t;
		cin >> a >> b;

		if(a == b)
		{
			cout << "YES" << endl;
			continue;
		}

		for(int i = 0; i < n; i++)
		{
			if(a[i] != b[i])
				s.push_back(a[i]), t.push_back(b[i]);
		}

		bool ok = false;

		a = t;
		b = s;
		b.push_back(s[0]);

		ok = ok || !kmp(a, b).empty();

		cout << (ok ? "YES" : "NO") << '\n';
	}

	return 0;
}
