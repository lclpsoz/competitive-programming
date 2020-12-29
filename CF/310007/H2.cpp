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
    
    int t; cin >> t;
    while(t--)
    {
        int n, k, m;
        cin >> n >> k >> m;
        vi x(n, 1);
        for(int i = 0; i < m; i++)
        {
            int b; cin >> b;
            x[--b] = 0;
        }

        if(((n - m) % (k - 1)))
        {
            cout << "NO" << endl;
            continue;
        }
        
        vi lft(n), rgh(n);
        for(int i = 0; i < n; i++) lft[i] = i - 1, rgh[i] = i + 1;
        lft[0] = rgh[n - 1] = -1;
        
        auto erase = [&](int i)
        {
            int l = lft[i];
            int r = rgh[i];

            if(r != -1) lft[r] = l;
            if(l != -1) rgh[l] = r;
        };

        int s = 0, q = 0, p = 0;
        bool ok = true;
        for(int i = 0; i != -1 && ok; i = rgh[i])
        {
            if(!x[i])
            {
                if(s == (n - m - q) / 2)
                {
                    break;
                }
            }
            else if(p) p--, erase(i);
            else
            {
                if(s == (n - m - q) / 2)
                {
                    if(s - 1 < k / 2 || lft[i] == -1) ok = false;
                    else
                    {
                        q += k - 1, p += k / 2;
                        int o = k / 2, j = lft[lft[i]];
                        while(j != -1 && o)
                        {
                            if(x[j]) erase(j), --o, --s;
                            j = lft[j];
                        }

                        if(o) ok = false;
                        else
                        {
                            i = lft[i];
                        }
                    }
                }
                else s++;
            }
        }

        if(!ok)
        {
            for(int i = 0; i < n; i++) lft[i] = i - 1, rgh[i] = i + 1;
            lft[0] = rgh[n - 1] = -1;

            s = 0, q = 0, p = 0;
            ok = true;
            for(int i = n - 1; i != -1 && ok; i = lft[i])
            {
                if(!x[i])
                {
                    if(s == (n - m - q) / 2)
                    {
                        break;
                    }
                }
                else if(p) p--, erase(i);
                else
                {
                    if(s == (n - m - q) / 2)
                    {
                        if(s - 1 < k / 2 || rgh[i] == -1) ok = false;
                        else
                        {
                            q += k - 1, p += k / 2;
                            int o = k / 2, j = rgh[rgh[i]];
                            while(j != -1 && o)
                            {
                                if(x[j]) erase(j), --o, --s;
                                j = rgh[j];
                            }

                            if(o) ok = false;
                            else
                            {
                                i = rgh[i];
                            }
                        }
                    }
                    else s++;
                }
            }
        }

        cout << (ok ? "YES" : "NO") << endl;
    }
    
    return 0;
}