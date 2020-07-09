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

const int N = 2e5+10;
int n;
ld arr[N];

ld eval (ld x) {
    ld ret = 0;/*
    for (int i = 0; i < n; i++) {
        ret += abs (arr[i] - x);
        printf ("||%Lf %Lf\n", arr[i]-x, ret);
    }*/
    
    
    ld now = 0;
    for (int i = 0; i < n; i++) {
        if (cmp (arr[i]-x, now+(arr[i]-x)) == 1)
            now = arr[i]-x;
        else
            now += arr[i]-x;
//         printf ("now: %Lf\n", now);
        ret = max (now, ret);
    }
    now = 0;
    for (int i = 0; i < n; i++) {
        if (cmp (-(arr[i]-x), now-(arr[i]-x)) == 1)
            now = -(arr[i]-x);
        else
            now += -(arr[i]-x);
        ret = max (now, ret);
    }
    
    return ret;
}

ld ternary () {
    ld l = -1e9, r = 1e9;
    int cnt = 0;
    while (cnt++ < 400) {
        ld a = (2*l + r)/3;
        ld b = (l + 2*r)/3;
        ld eTl = eval (a);
        ld eTr = eval (b);
//            printf ("%Lf %Lf, %Lf %Lf, %Lf %Lf\n", l, r, a, b, eTl, eTr);
        if (cmp (eTl, eTr) == -1)
            r = b;
        else
            l = a;
    }
    
    return eval (l);
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        scanf ("%Lf", &arr[i]);
    
//      for (ld i = -1; i < 3; i += 0.01)
//          printf ("%Lf\t%Lf\n", i, eval (i));
//     
     printf ("%.20Lf\n", ternary());
    
    return 0;
}
