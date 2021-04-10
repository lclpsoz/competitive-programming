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
    
    int n; cin >> n;
    vi x(n);
    for(int& i : x) cin >> i;
    reverse(ALL(x));
    x.emplace_back(x.back());
    vector<ll> a = {1};
    if(x[1] == 0) a.back() = -1;
    for(int i = 1; i < n; i++)
    {
        // for(int j = 0; j < LEN(a); j++)
        //     cout << a[j] << " \n"[j == LEN(a) - 1];
     
        vector<ll> b;
        if(x[i + 1])
        {
            b.emplace_back(1);
            if(x[i])
            {
                int j = 0;
                while(LEN(b) < LEN(a) + 1)
                    b.emplace_back(b.back() + a[j++]);
            }
            else
            {
                int j = LEN(a) - 1;
                while(LEN(b) < LEN(a) + 1)
                    b.emplace_back(b.back() - a[j--]);
                reverse(ALL(b));
            }
        }
        else
        {
            b.emplace_back(-1);
            if(x[i])
            {
                int j = LEN(a) - 1;
                while(LEN(b) < LEN(a) + 1)
                    b.emplace_back(b.back() - a[j--]);
                reverse(ALL(b));
            }
            else
            {
                int j = 0;
                while(LEN(b) < LEN(a) + 1)
                    b.emplace_back(b.back() + a[j++]);
            }
        }

        if(abs(b.back()) > (ll)1e9 || abs(b[0]) > (ll)1e9)
        {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }

        swap(a, b);
    }

    for(int i = 0; i < n; i++)
        cout << a[i] << " \n"[i == n - 1];
    
    return 0;
}