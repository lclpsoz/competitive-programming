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
		
		int min_cnt = 1e9;
		for(char c : s)
		{
			if(c == ch) cnt++;
			else
			{
				v.emplace_back(ch, cnt);
				cnt = 1, ch = c;
				min_cnt = min(min_cnt, cnt);
			}
		}
		v.emplace_back(ch, cnt);
		min_cnt = min(min_cnt, cnt);
		
		vi pos;
		for(int i = 0; i < LEN(v); i++)
		{
			auto [c, x] = v[i];
			// cerr << c << x;
			if(pw.count(x)) pos.emplace_back(i);
		}
		// cerr << endl;
		int best = -1;
		if (!empty(pos))
		{
			for (int i = 0; i < pos.size() - 1; i++) 
			{
				char val;
				if (v[pos[i]].second > 1) {
					std::stringstream ss;
					ss<< std::hex << v[pos[i]].second;
					std::string hexi(ss.str());
					val = hexi[hexi.size() - 1];
				} else {
					val = v[pos[i]].first;
				}
				if (val >= v[pos[i] + 1].first) 
				{
					best = pos[i];
					break;
				}
			}
			if (best == -1)
				best = pos[pos.size() - 1];
			
			v[best].second--;
		}
		else
		{
			// v[0].second--;
			for(int i = 0; i < LEN(v); i++)
			{
				stringstream stream;
				stream << std::hex << v[i].second;
				string n(stream.str());
				int j = LEN(n) - 1;
				while(n[j] == '0') j--;
				if(n[j] == 'a') continue;
				v[i].second--;
				break;
			}
		}

		for(int i = 0; i < v.size(); i++)
		{
			char c = v[i].first;
			int x = v[i].second;
			if(!x) continue;
			if(x == 1) {
				cout << c;
				continue;
			}
			stringstream stream;
			stream << std::hex << x;
			string n(stream.str());
			for(char& b : n) b = toupper(b);
			// if(n == "1") n = "";
			// cout << c << x << ": "  << c << n << endl;
			cout << c << n;
		}
		cout << '\n';
	}

	return 0;
}
