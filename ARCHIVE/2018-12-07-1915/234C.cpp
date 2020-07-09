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

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
  return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 1e5+10;

int n;
int arr[N];
int pref[N], pos[N];
int ans = N;

int main () {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &arr[i]);
        if (arr[i] > 0) arr[i] = 1;
        else if (arr[i] < 0) arr[i] = -1;
    }
    for (int i = n-1; i > 0; i--)
        pos[i] = pos[i+1] + (arr[i] <= 0);
    pref[0] = arr[0] >= 0;
    for (int i = 1; i < n; i++)
        pref[i] = pref[i-1] + (arr[i] >= 0);
    
    for (int i = 0; i < n-1; i++) {
        //printf ("%d: %d %d\n", i, pref[i], pos[i+1]);
        ans = min (ans, pref[i]+pos[i+1]);
    }
    printf ("%d\n", ans);
    
    return 0;
}
