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

class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> vals;
        for (int i = 0; i < n; i++)
            vals.push_back({__builtin_popcount(nums[i]), nums[i]});
        sort(vals.begin(), vals.end());
        vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
        
        long long ans = 0;
        for (int i = vals.size()-1; i >= 0; i--) {
            cout << "vals.size() = "<< vals.size() << '\n';
            if (vals[i].first >= k) {
                ans += 2*vals.size() - 1; // - duplicate of (x, x)
            }
            else if (vals[i].first < k/2 || (k%2 == 1 && vals[i].first == k/2))
                break;
            else {
                auto it = lower_bound(vals.begin(), vals.end(), make_pair(k-vals[i].first, -1));
                int dist_begin = it - vals.begin();
                int count_pairs = vals.size() - dist_begin;
                ans += 2*count_pairs - 1;
            }
            
            vals.pop_back();
        }
        
        return ans;
    }
};

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.precision(10);
    Solution x;
    vector<int> nums = vector<int>{1, 2, 3, 1};
    cout << x.countExcellentPairs(nums, 3) << '\n';

	return 0;
}
