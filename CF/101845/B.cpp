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

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

void flip(char& c)
{
    c = (c == '1' ? '0' : '1');
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

    string a, b;
    cin >> a >> b;
    int n = LEN(a);

    a = a + a;
    vi cnt(n + n + 1, 0);

    for(int i = 1; i <= n + n; i++)
        cnt[i] = cnt[i - 1] + bool(a[i - 1] == '1');

    int cnt2 = 0;
    for(int i = 0; i < n; i++)
        cnt2 += bool(b[i] == '1');

    int ans = n + 10;
    for(int i = 0; i < n; i++)
    {
        if((cnt2 % 2) != ((cnt[i + n] - cnt[i]) % 2)) continue;

        {
            string c = b;
            int now = 0;
            for(int j = 0; j < n - 1; j++)
            {
                if(c[j] == a[j + i]) continue;
                now++;
                flip(c[j]);
                flip(c[j + 1]);
            }

            assert(c == a.substr(i, n));
            ans = min(ans, now);
        }
        {
            string c = b;
            int now = 1;
            flip(c[0]);
            flip(c[n - 1]);
            for(int j = 0; j < n - 1; j++)
            {
                if(c[j] == a[j + i]) continue;
                now++;
                flip(c[j]);
                flip(c[j + 1]);
            }

            assert(c == a.substr(i, n));
            ans = min(ans, now);
        }
    }

    if(ans == n + 10) ans = -1;
    cout << ans << endl;

	return 0;
}
