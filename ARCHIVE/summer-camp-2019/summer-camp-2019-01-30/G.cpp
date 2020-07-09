#include "bits/stdc++.h"
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 360000;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 600100;


void zfunction (int s[], int z[], int n) {
    fill (z, z+n, 0);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r) z[i] = min (r-i+1, z[i-l]);
        while (i + z[i] < n and s[z[i]] == s[i+z[i]])
            ++z[i];
        if (i+z[i]-1 > r)
            l = i, r = i+z[i]-1;
    }       
}

int main () {
    int n;
//     int a[200100], t[N], z[N];
    int a[200100], b[200100], t[N], z[N];
    scanf ("%d", &n);
    int st;
    
    for (int i = 0; i < n; i++)
        scanf ("%d", &a[i]);
    for (int i = 0; i < n; i++)
        scanf ("%d", &b[i]);
    sort (a, a+n);
    sort (b, b+n);
//     for (int i = 0; i < n; i++)
//         printf ("%d %d\n", a[i], b[i]);
    
    for (int i = 0; i < n; i++) {
        if (i == 0)
            st = a[i];
        else
            a[i-1] = mod (a[i-1]-a[i]);
    }
    a[n-1] = mod (a[n-1]-st);
    for (int i = 0; i < n; i++) {
        if (i == 0)
            st = b[i];
        else
            b[i-1] = mod (b[i-1]-b[i]);
    }
    b[n-1] = mod (b[n-1]-st);
    
//     for (int i = 0; i < n; i++)
//         printf ("b[%d]: %d\n", i, b[i]);
    
    for (int i = 0; i < n; i++)
        t[i] = a[i];
    t[n] = -10101010;
    for (int i = n+1; i <= 2*n; i++)
        t[i] = b[i-n-1];
    for (int i = 2*n+1; i <= 3*n; i++)
        t[i] = b[i-(2*n+1)];
    
//     for (int i = 0; i <= 3*n+1; i++)
//         printf ("%d: %d\n", i, t[i]);
        
    zfunction (t, z, 3*n+1);
    int ans = 0;
    for (int i = 0; i < 3*n+1; i++)
        ans = max (ans, z[i]);
    printf ("%s\n", ans == n ? "possible" : "impossible");
    
    
    
//     for (int i = 0; i < n; i++)
//         printf ("%d %d\n", a[i], b[i]);
//     sort (a, a+n);
//     sort (b, b+n);
    
//     for (int i = 0; i < n; i++)
//         printf ("%d %d\n", a[i], b[i]);
    
//     for (int i = 0; i < n; i++) {
//         scanf ("%d", &t[i]);
//         if (i == 0)
//             st = t[i];
//         else
//             t[i-1] = mod (t[i-1]-t[i]);
//     }
//     t[n-1] = mod (t[n-1]-st);
//     t[n] = '#';
//     for (int i = n+1; i <= n+n; i++) {
//         scanf ("%d", &t[i]);
//         if (i == 0)
//             st = t[i];
//         else
//             t[i-1] = mod (t[i-1]-t[i]);
//     }
//     t[n+n] = mod (t[n+n]-st);
//     
//     for (int i = n+1; i <= n+n; i++)
//         t[i+n] = t[i];
//     for (int i = 0; i <= 3*n; i++)
//         printf ("%d\n", t[i]);
    

	return 0;
}
