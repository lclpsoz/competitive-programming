#include <bits/stdc++.h>
using namespace std;

// --
#define x first
#define y second
#define len(x) ((int)x.size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod(ll x, int m = MOD) {
    return (int)(((x%m) + m)%m);
}
// --

int main() {
    ios_base::sync_with_stdio(false);

    string a, b; cin >> a >> b;
    int n = len(a), m = len(b), ans = 0;
    
    if(n <= m)
    {
        int pre = 0, suf = 0;

        for(int i = 0; i < n; i++)
        {
            if(a[i] != b[i])
                break;
            pre++;
        }

        for(int i = n - 1, j = m - 1; i >= 0; i--, j--)
        {
            if(a[i] != b[j])
                break;
            suf++;
        }

        if(pre == n || suf == n)
            ans = m - n;
        else
            ans = m - pre - suf;
    }
    else
    {
        int pre = 0, suf = 0;

        for(int i = 0; i < m; i++)
        {
            if(a[i] != b[i])
                break;
            pre++;
        }

        for(int i = n - 1, j = m - 1; j >= 0; i--, j--)
        {
            if(a[i] != b[j])
                break;
            suf++;
        }

        if(pre + suf >= m)
            ans = 0;
        else
            ans = m - pre - suf;

    }

    cout << ans << endl;

    return 0;
}