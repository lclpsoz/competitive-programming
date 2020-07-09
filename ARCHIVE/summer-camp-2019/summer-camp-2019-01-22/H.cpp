#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> pii;

#define x first
#define y second

const int N = 1e5+10;

ll ans = 0;
int n, k;
multiset<int> st;

int main()
{
    while (scanf ("%d %d", &n, &k) != EOF) {
        ans = 0;
        int pts = 0;
        st.clear();
        for (int i = 0; i < n; i++) {
            int x; scanf ("%d", &x);
            ans += x;
            if (pts == k) {
                st.insert (x);
                ans -= x;
                pts = 0;
            }
            else if (!st.empty() and (*st.begin()) < x) {
                ans += (*st.begin());
                ans -= x;
                st.erase (st.begin());
                st.insert (x);
                ++pts;
            } else
                ++pts;
//             printf ("%d %lld %d\n", (int)st.size(), ans, pts);
        }
        
        printf ("%lld\n", ans);
    }
    return 0;
}
