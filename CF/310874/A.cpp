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



int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	map<string, int> mp;
	mp["C"] = 0;
	mp["C#"] = 1;
	mp["D"] = 2;
	mp["D#"] = 3;
	mp["E"] = 4;
	mp["F"] = 5;
	mp["F#"] = 6;
	mp["G"] = 7;
	mp["G#"] = 8;	
	mp["A"] = 9;
	mp["A#"] = 10;
	mp["B"] = 11;

	int tt; cin >> tt;
	while(tt--)
	{
		string a, b, c;
		cin >> a >> b >> c;

		int aa = mp[a];
		int bb = mp[b];
		int cc = mp[c];

		while(aa > bb)
			bb += 12;
		while(bb > cc)
			cc += 12;

		if(bb - aa == 4 && cc - bb == 3) cout << "Major triad\n";
		else if(bb - aa == 3 && cc - bb == 4) cout << "Minor triad\n";
		else cout << "Dissonance\n"; 
	}

	return 0;
}
