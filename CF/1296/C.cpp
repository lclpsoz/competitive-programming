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

  ll SHIFT = 1e6;

	int t, n;
	string str;
  map<ll, int> mp;
  
	
	cin >> t;
	while (t--) {
    mp.clear();
    mp[0] = 1;

	  cin >> n;
	  cin >> str;
	  int left, right; left = 1e9; right = 2e9;
	  ll cur = 0;
	  for (int i = 2; i <= n+1; i++) {
	    char c = str[i-2];
      if (c == 'L')
        cur--;
      else if (c == 'R')
        cur++;
      else if (c == 'U')
        cur += SHIFT;
      else if (c == 'D')
        cur -= SHIFT;
      
      // cout << "bef >> cur = " << cur << " <><> mp[cur] = " << mp[cur] << endl;
  	  if (mp[cur] && right - left > i - mp[cur])
        left = mp[cur], right = i-1;
      mp[cur] = i;
  	  // cout << ">>" << left << ' ' << right << " i = " << i << " cur = " << cur << endl;
  	}
  	
  	if (left == 1e9)
  	  cout << -1 << endl;
  	else
  	  cout << left << ' ' << right << endl;
	}

	return 0;
}
