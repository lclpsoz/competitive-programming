#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

#define LEN(x) (int)x.size()
#define ALL(x) x.begin(), x.end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;
using vpii = vector<pii>;

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

template<typename T>
const T INF = (is_same<T, int>::value ? 1e9 : 1e18);
const int MOD = 1e9 + 7;
const double EPS = 1e-9;

inline int fcmp(double x, double y)
{ return (x < y + EPS ? (x < y - EPS ? -1 : 0) : 1);}

struct range
{
    int l, r, color;
    range(int x = 0, int y = 0, int c = 0) : l(x), r(y), color(c) {}
    bool operator < (const range& o) const 
    { return l < o.l; }
};
 
set<range> ranges;
 
void add(int l, int r, int color)
{
    if(l > r) return;
    
    if(empty(ranges))
    {
        ranges.insert(range(l, r, color));
        return;
    }
    
    auto it = ranges.lower_bound(l);
    
    if(it != ranges.begin())
    {
        --it;
        if(color == it->color)
        {
            l = min(l, it->l);
            ranges.erase(it);
        }
        else if(it->l <= l && it->r >= r)
        {
            auto [a, b, c] = *it;
            ranges.erase(it);
            ranges.insert(range(a, l - 1, c));
            ranges.insert(range(l + 1, b, c));
        }
    }
 
    ranges.insert(range(l, r, color));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    
    int n; cin >> n;
    map<int, vi> mp;
    vi a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[-a[i]].emplace_back(i);
    }
    vector<ll> dp(n);

    for(auto& [c, v] : mp)
    {
        // cout << "ranges:";
        // for(auto [l, r, color] : ranges)
        //     cout << " (" << l << ", " << r << ", " << color << ")";
        // cout << endl;

        for(int p : v)
        {
            dp[p] = 0;
            auto it = ranges.upper_bound(p);
            if(it != ranges.begin())
            {
                --it;
                dp[p] = max(dp[p], abs(p - it->l) + dp[it->l]);
                if(it->r > p)
                    dp[p] = max(dp[p], abs(p - it->r) + dp[it->r]);
                else if(++it != ranges.end())
                    dp[p] = max(dp[p], abs(p - it->r) + dp[it->r]);
            }
            else if(it != ranges.end())
                dp[p] = max(dp[p], abs(p - it->r) + dp[it->r]);
        }

        for(int p : v)
            add(p, p, -c);
    }

    for(int i = 0; i < n; i++)
        cout << dp[i] << " \n"[i == n - 1];

    return 0;
}