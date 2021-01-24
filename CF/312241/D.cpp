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



int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int tt; cin >> tt;
	while(tt--)
	{
		string s; int k;
		cin >> s >> k;
		int sz = 0;
		string ans;
		bool ok = true;
		for(int i = 0; i < LEN(s) && ok; i++)
		{
			if(s[i] >= 'a' && s[i] <= 'z')
			{
				if(i == 0 || (s[i - 1] >= 'a' && s[i - 1] <= 'z'))
					sz++, ans.push_back(s[i]);
				else
				{
					int j = i - 1;
					while(j >= 0 && s[j] >= '0' && s[j] <= '9') j--;
					j++;
					if(i - j > 6) ok = false;
					else
					{
						int d = stoi(s.substr(j, i - j));
						ans += string(d, s[i]);
						sz += d;
					}
				}
			}

			if(sz > k) ok = false;
		}
		if(!ok)
			cout << "unfeasible\n";
		else
			cout << ans << '\n';
	}

	return 0;
}
