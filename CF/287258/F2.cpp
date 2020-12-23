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

	int t;
	cin >> t;
	while (t--) {
		string s; cin >> s;
		vi cnt(6, 0);
		bool ans = false;
		for (int i = 0; i < 7 && !ans; i++)
			for (int j = i + 1; j < 7 && !ans; j++)
			{
				for(int z = 1; z <= 5; z++)
					cnt[z] = 0;
				for(int z = 0; z < 7; z++)
					if(z != i && z != j) cnt[s[z] - 'A' + 1]++;
				
				{
					bool ok = true;
					for(int z = 1; z <= 5 && ok; z++) if(cnt[z] != 1) ok = false;
					ans = ok;
				}
				int a = (s[i] - 'A') + 2 + (s[j] - 'A');
				if(a > 5) continue;

				for (int k = 0; k < 7 && !ans; k++)
				{
					if(k == i || k == j) continue;
					

					for(int z = 1; z <= 5; z++)
						cnt[z] = 0;
					cnt[a]++;
					for(int z = 0; z < 7; z++)
						if(z != i && z != j && z != k) cnt[s[z] - 'A' + 1]++;
					{
						bool ok = true;
						for(int z = 1; z <= 5 && ok; z++) if(cnt[z] != 1) ok = false;
						ans = ok;
					}
					
					for (int l = k + 1; l < 7 && !ans; l++)
					{
						if(l == j || l == i) continue;
						int b = (s[k] - 'A') + 2 + (s[l] - 'A');
						if(b > 5 || a == b) continue;

						for(int z = 1; z <= 5; z++)
							cnt[z] = 0;
						cnt[a]++, cnt[b]++;
						for(int z = 0; z < 7; z++)
							if(z != i && z != j && z != k && z != l) cnt[s[z] - 'A' + 1]++;

						bool ok = true;
						for(int z = 1; z <= 5 && ok; z++) if(cnt[z] != 1) ok = false;
						ans = ok;
					}
				}
			}

		if (ans)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}


	return 0;
}
