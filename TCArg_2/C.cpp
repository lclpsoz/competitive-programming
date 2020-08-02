#include "bits/stdc++.h"
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
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



int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int p, n;
	cin >> n >> p;
	string s; cin >> s;

	for(int i = 0; i < n - p; i++)
	{
		if(s[i] == '.' && s[i + p] != '.') s[i] = s[i + p] == '0' ? '1' : '0';
		else if(s[i] == '.' && s[i + p] == '.') s[i] = '1', s[i + p] = '0';
		else if(s[i + p] == '.') s[i + p] = s[i] == '0' ? '1' : '0';
	}
	
	for(int i = 0; i < n; i++)
		if(s[i] == '.') s[i] = '0';

	for(int i = 0; i < n - p; i++)
	{
		if(s[i] != s[i + p])
		{
			cout << s << endl;
			return 0;
		}
	}	

	cout << "No" << endl;
	return 0;
}
