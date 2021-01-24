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

const int N = 1e3 + 10;
int dist[N][N];
int n, m, k, o, t;
int d[N], seq[N], val[N];
vi adj[N], q;

void bfs(int s)
{   
    dist[s][s] = 0;
    q.clear();
    q.emplace_back(s);
    for(int i = 0; i < LEN(q); i++)
    {
        int v = q[i];
        for(int u : adj[v])
            if(dist[s][u] == -1)
            {
                dist[s][u] = dist[s][v] + 1;
                q.emplace_back(u);
            }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    
    memset(dist, -1, sizeof dist);

    cin >> n >> m >> k;

    while(m--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }

    for(int i = 1; i <= n; i++) bfs(i);

    cin >> o >> t; t /= k;
    for(int i = 1; i <= o; i++) cin >> seq[i];
    seq[0] = 1;
    seq[o + 1] = 1;

    for(int i = 1; i <= o; i++)
        cin >> d[i] >> val[i];

    vi dp(t + 1, -INF<int>), dp_new(t + 1);
    dp[0] = 0;
    for(int i = 1; i <= o + 1; i++)
    {
        for(int j = 0; j <= t; j++)
        {
            dp_new[j] = -INF<int>;
            int ts1 = dist[seq[i - 1]][seq[i]];
            int ts2 = dist[seq[i - 1]][d[i - 1]] + dist[d[i - 1]][seq[i]];
            if(j >= ts1) dp_new[j] = max(dp_new[j], dp[j - ts1]);
            if(d[i - 1] && j >= ts2) dp_new[j] = max(dp_new[j], dp[j - ts2] + val[i - 1]);
        }

        swap(dp, dp_new);
    }

    int ans = *max_element(ALL(dp));
    if(ans < 0) cout << "Impossible" << endl;
    else cout << ans << endl;
    
    return 0;
}