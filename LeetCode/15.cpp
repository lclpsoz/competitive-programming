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
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<bool> jump(n, false);
        
        vector<pair<int, int>> vals;
        for (int i = 0; i < n; i++)
            vals.push_back({nums[i], i});
        sort(vals.begin(), vals.end());
        
        int count = 0, cur_val = -1e9;
        for (int i = 0; i < n; i++) {
            if (vals[i].first != cur_val) {
                cur_val = vals[i].first;
                count = 1;
            }
            else
                count++;
            if (count > 3)
                jump[vals[i].second] = true;
        }
        
        vector<pair<int, int>> aux;
        for (int i = 0; i < n; i++)
            if (!jump[vals[i].second])
                aux.push_back(vals[i]);
        vals = aux;
        
        vector<vector<int>> ans;
        for (auto i = vals.begin(); i != vals.end(); i++)
            for (auto j = i+1; j != vals.end(); j++) {
                int sum = i->first + j->first;
                auto it = lower_bound(j+1, vals.end(), pair<int, int>(-sum, -1));
                if (it != vals.end() && it->first == -sum) {
                    ans.push_back(vector<int>{i->first, j->first, it->first});
                }
            }
        sort(ans.begin(), ans.end());
        ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
        
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
    vector<int> nums = vector<int>{-1,0,1,2,-1,-4};
    for (vector<int> tup : x.threeSum(nums))
        cout << tup[0] << ' ' << tup[1] << ' ' << tup[2] << '\n';
        

	return 0;
}
