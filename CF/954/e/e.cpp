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
const ld EPS = 1e-15;
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

const int DBG = 0;

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(30);

	int n, target;
	cin >> n >> target;
	vi _maxi(n), _temp(n);
	vi maxi(n), temp(n);
	for(int &v : _maxi) cin >> v;
	for(int &v : _temp) cin >> v;
	vpii inp;
	for(int i = 0; i < n; i++)
		inp.push_back({_temp[i], _maxi[i]});
	sort(ALL(inp));
	for(int i = 0; i < n; i++)
		maxi[i] = inp[i].y, temp[i] = inp[i].x;
	

	if(*max_element(ALL(temp)) < target or target < *min_element(ALL(temp)))
		cout << 0 << '\n';
	else {
		ll sum = 0;
		ll total = 0;
		for(int i = 0; i < n; i++) {
			sum += maxi[i]*1LL*temp[i];
			total += maxi[i];
		}
		if(DBG)
			cerr << "sum, total = " << sum << ' ' << total << ' ' << fcmp(sum/total, target) << '\n';
		int bs_l = 1;
		if(sum > total*target) {
			reverse(ALL(maxi));
			reverse(ALL(temp));
			bs_l = -1;
		}
		int pos = 0;
		ld ans = 0;
		bool found = false;
		while(!found and sum != total*target) {
			assert(pos < n);
			sum -= maxi[pos]*1LL*temp[pos];
			total -= maxi[pos];
			if(DBG) {
				cerr << "pos = " << pos << '\n';
				cerr << "  sum, total = " << sum << ' ' << total << ' ' << fcmp(sum/total, target) << '\n';
			}
			if((bs_l == 1 and sum > target*total) or
				(bs_l == -1 and sum < target*total)) {
				ld l = 0, r = maxi[pos];
				for(int i = 0; i < 300; i++) {
					// if(DBG)
					// 	cerr << "    l = " << l << ' ' << "r = " << r << '\n';
					ld md = (l+r)/2;
					ld val = (sum+md*temp[pos])/(total+md);
					if((bs_l == 1 and val > target) or
						(bs_l == -1 and val < target))
						l = md;
					else
						r = md;
				}
				// sum += l*temp[pos];
				// total += l;
				ans += l;
				if(DBG) {
					cerr << "  sum, total = " << fixed <<  sum << ' ' << fixed << total << ' ' << fcmp(sum/total, target) << '\n';
					cerr << "     ";
					cerr << fixed << sum/total << '\n';
					cerr << "     ";
					cerr << setprecision(20) << fixed << target-sum/total << '\n';
				}
				found = true;
			}
			++pos;
		}
		while(pos < n) ans += maxi[pos++];
		cout << fixed << ans << '\n';
	}

	return 0;
}
