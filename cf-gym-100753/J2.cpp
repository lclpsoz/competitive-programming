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
    
    int g, c, n;
    cin >> g >> c >> n;
    
    vector<tuple<int, int, int>> x;

    for(int i = 0; i < n; i++)
    {
        string t;
        int p, s;
        cin >> t >> p >> s;

        if(t == "generous")
            x.emplace_back(0, p, s);
        else if(t == "honest")
            x.emplace_back(1, p, s);
        else
            x.emplace_back(2, p, s);
    }

    vvi dp_old(c + 1, vi(g * n + 10, -INF<int>));
    vvi dp_new(c + 1, vi(g * n + 10, -INF<int>));
    dp_old[c][0] = 0;
    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        auto [t, p, s] = x[i];

        int z1 = (g - s) / p;
        int z2 = (g - s + p - 1) / p;

        for(int j = 0; j <= c; j++)
        {
            for(int k = 0; k <= g * n; k++)
            {
                dp_new[j][k] = dp_old[j][k];
                if(t == 0)
                {
                    int d = p * z2;
                    if(k >= s)
                        dp_new[j][k] = max(dp_new[j][k], 1 + dp_old[j][k - s]);
                    else if(j && k >= d)
                        dp_new[j][k] = max(dp_new[j][k], 1 + dp_old[j - 1][k - d]);
                }
                else if(t == 1)
                {
                    int d = p * (((p * z1) % (g - s)) < ((p * z2) % (g - s)) ? z1 : z2);
                    if(k >= s)
                        dp_new[j][k] = max(dp_new[j][k], 1 + dp_old[j][k - s]);
                    if(j && k >= d)
                        dp_new[j][k] = max(dp_new[j][k], 1 + dp_old[j - 1][k - d]);
                }
                else
                {
                    int d = p * z1;
                    if(k >= s)
                        dp_new[j][k] = max(dp_new[j][k], 1 + dp_old[j][k - s]);
                    if(j && k >= d)
                        dp_new[j][k] = max(dp_new[j][k], 1 + dp_old[j - 1][k - d]);
                }

                ans = max(ans, dp_new[j][k]);
            }
        }

        swap(dp_old, dp_new);
    }

    cout << ans << endl;

    return 0;
}