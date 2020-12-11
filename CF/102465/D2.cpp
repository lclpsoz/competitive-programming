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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    
    int x, y, n;
    cin >> x >> y >> n;

    swap(x, y);
    vector<int> mn(y, x), mx(y, -1);

    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        swap(a, b);
        mn[b] = min(mn[b], a);
        mx[b] = max(mx[b], a);
    }

    multiset<int> st1, st2, st_mn;
    
    ll sum1 = 0, sum2 = 0;
    for(int i = 0; i < y; i++)
    {
        if(mn[i] < x)
        {
            st_mn.insert(mn[i]);
            st2.insert(mx[i]);
            sum2 += mx[i];
        }
    }

    ll ans = INF<ll>;

    for(int i = 0; i < x; i++)
    {
        ans = min(ans, y - 1 + 2 * (sum1 + sum2));

        int d = (int)st_mn.count(i);
        st_mn.erase(i);
        sum1 += d + LEN(st1);
        while(d--) st1.insert(i);
        st2.erase(i);
        sum2 -= LEN(st2);
    }

    cout << ans << endl;
    
    return 0;
}