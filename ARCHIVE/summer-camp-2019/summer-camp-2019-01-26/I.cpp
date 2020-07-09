#include<bits/stdc++.h>
using namespace std;

// ------------------------------------------------------------
#define x first
#define y second
#define len(x) ((int)(x).size())
using ll = long long;
using llu = long long unsigned;
using ld = long double;
using pii = pair<int, int>;

const ld EPS = 1e-9;
inline int cmp (ld x, ld y = 0, ld tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
    return (int)(((x%m) + m) % m);
}



// ------------------------------------------------------------

const int N = 1e5+10;

int n, m;
int arr1[N], arr2[N];

ll eval (int x) {
    ll ret = 0;
    for (int i = 0; i < n and arr1[i] < x; i++)
        ret += abs (x-arr1[i]);
    for (int i = 0; i < m and arr2[i] > x; i++)
        ret += abs (arr2[i]-x);
    
    return ret;
}

int main () {
    scanf ("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf ("%d", &arr1[i]);
    for (int i = 0; i < m; i++)
        scanf ("%d", &arr2[i]);
    sort (arr1, arr1+n);
    sort (arr2, arr2+m, greater<int>());
    
    int l, r;
    l = 0, r = 1e9+10;
//     while (l < r) {
//         int a = (2*l + r)/3;
//         int b = (l + 2*r)/3;
//         ll va = eval (a);
//         ll vb = eval (b);
//         if (va == vb)
//             l = a, r = b;
//         if (va < vb)
//             r = b-1;
//         else
//             l = a+1;
//     }
    while (l < r) {
        int md = (l+r)/2;
        int eMd = eval (md);
        int eMd1 = eval (md+1);
//         printf ("(%d, %d, %d) %d %d\n", l, md, r, eMd, eMd1);
        if (eMd == eMd1)
            l = r = md;
        else if (eMd < eMd1)
            r = md;
        else
            l = md+1;
    }
    printf ("%lld\n", eval (l));
    
    return 0;
}
