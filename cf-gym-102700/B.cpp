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

vector<int> suffix_array(const string& s)
{
	int n = LEN(s);
	vector<int> rnk(n), sa(n), aux(n), cnt(max(256, n));

	auto counting_sort = [&](int k)
	{
		fill(cnt.begin(), cnt.end(), 0);
		
		for(int i = 0; i < n; i++)
			cnt[(i + k < n ? rnk[i + k] : 0)]++;
		
		for(int i = 0, sum = 0; i < max(256, n); i++)
		{
			int now = cnt[i];
			cnt[i] = sum;
			sum += now;
		}

		for(int i = 0; i < n; i++)
			aux[cnt[(sa[i] + k < n ? rnk[sa[i] + k] : 0)]++] = sa[i];

		sa = aux;
	};

	auto mp = [&](int i, int k)
	{
		return pair<int, int>(rnk[sa[i]], (sa[i] + k < n ? rnk[sa[i] + k] : 0));
	};

	for(int i = 0; i < n; i++)
		sa[i] = i, rnk[i] = s[i];

	for(int k = 1; k < n; k *= 2)
	{
		counting_sort(k);
		counting_sort(0);
		
		int r = 0;
		aux[sa[0]] = r;
		for(int i = 1; i < n; i++)
			aux[sa[i]] = (mp(i, k) == mp(i - 1, k) ? r : ++r);
		rnk = aux;

		if(rnk[sa[n - 1]] == n - 1) break;
	}

	return sa;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	// s = "ACB";
	// s += "#";
	// auto sa = suffix_array(s);

	// 3 #
	// 0 ACB#
	// 2 B#
	// 1 CB#

	string s1, s2;
	cin >> s1 >> s2;
	s1 += '#';
	s2 += '#';
	int mx1 = suffix_array(s1).back();
	int mx2 = suffix_array(s2).back();

	int p = mx1;
	while(true) {
		cout << s1[p++];
		if(p == LEN(s1)-1 or s2[mx2] > s1[p]) {
			while(mx2 < LEN(s2)-1)
				cout << s2[mx2++];
			break;
		}
	}
	cout << '\n';
	

	return 0;
}
