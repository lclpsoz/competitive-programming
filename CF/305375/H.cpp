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



int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);
	
	set<int> pw;

	{
		// stringstream stream;
		// stream << std::hex << 160;
		// string n(stream.str());
		// cout << 160 << ": " << n << endl;

		int p = 1;
		while(p <= (int)1e6) pw.insert(p), p *= 16;
	}

	string s;
	while(cin >> s)
	{
		vector<pair<char, int>> v;
		char ch = s[0];
		int cnt = 0;
		for(char c : s)
		{
			if(c == ch) cnt++;
			else
			{
				v.emplace_back(ch, cnt);
				cnt = 1, ch = c;
			}
		}
		v.emplace_back(ch, cnt);
		
		vi pos;
		for(int i = 0; i < LEN(v); i++)
		{
			auto [c, x] = v[i];
			// cerr << c << x;
			if(pw.count(x) || x == 2) pos.emplace_back(i);
		}
		// cerr << endl;

		if(!empty(pos))
		{
			int k1 = LEN(v), k2 = -1, k3 = -1, k4 = -1;
			for(int i : pos)
			{
				if(v[i].second == 1)
				{
					if(i + 1 == LEN(v) || v[i + 1].first < v[i].first)
						k1 = min(k1, i);
					else
						k2 = max(k2, i);
				}
				else if(v[i].second == 2)
				{
					if(i + 1 == LEN(v)) k4 = i;
					else k4 = max(k4, i);
				}
				else k3 = max(k3, i);
			}

			if(k1 != LEN(v)) v[k1].second--;
			else v[max({k2, k3, k4})].second--;
		}
		else
		{
			v[0].second--;
		}

		for(auto [c, x] : v)
		{
			if(!x) continue;
			stringstream stream;
			stream << std::hex << x;
			string n(stream.str());
			for(char& b : n) b = toupper(b);
			if(n == "1") n = "";
			// cout << c << x << ": "  << c << n << endl;
			// if(1 + LEN(n) > x) cout << string(x, c);
			// else cout << c << n;
			cout << c << n;
		}
		cout << '\n';
	}

	return 0;
}
