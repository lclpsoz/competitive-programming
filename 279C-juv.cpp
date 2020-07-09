#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

#define LEN(x) (int)x.size()
#define ALL(x) x.begin(), x.end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

const ll INF = 1e18;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;

inline int fcmp(double x, double y)
{ return (x < y + EPS ? (x < y - EPS ? -1 : 0) : 1);}

int main()
{
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    
    int n, m; cin >> n >> m;

    vi a(n);
    for(int& ai : a) cin >> ai;

    int inc[n + 1], dec[n + 1];

    int count = 0;
    for(int i = 0, j = 0; i < n; i++)
    {
        j = max(i, j);
        while(j + 1 < n && a[j] <= a[j + 1]) {
            j++;
            count++;
        }

        inc[i] = j;
    }

    for(int i = 0, j = 0; i < n; i++)
    {
        j = max(i, j);
        while(j + 1 < n && a[j] >= a[j + 1]) {
            j++;
            count ++;
        }
        
        dec[i] = j;
    }
    cout << "count: " << count << '\n';

    while(m--)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;

        if(dec[l] >= r || inc[l] >= r || dec[inc[l]] >= r)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}
