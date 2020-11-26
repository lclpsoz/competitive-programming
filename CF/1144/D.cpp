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

const int N = 2e5 + 10;

int n;
int a[N];
int qnt[N], mx, bst, pos;
vector<pair<int, pii>> ans;

int main () {
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &a[i]);
        qnt[a[i]]++;
        if (qnt[a[i]] > mx) {
            mx = qnt[a[i]];
            bst = a[i];
            pos = i;
        }
    }
    
    for (int i = pos; i >= 2; i--) {
        if (a[i-1] == bst) continue;
        if (a[i-1] > a[i])
            ans.push_back ({2, {i-1, i}});
        else
            ans.push_back ({1, {i-1, i}});
        a[i-1] = bst;
    }
    
    for (int i = pos; i < n; i++) {
        if (a[i+1] == bst) continue;
        if (a[i+1] > a[i])
            ans.push_back ({2, {i+1, i}});
        else
            ans.push_back ({1, {i+1, i}});
        a[i+1] = bst;
    }
    printf ("%d\n", len (ans));
    for (auto p : ans)
        printf ("%d %d %d\n", p.x, p.y.x, p.y.y);
    

	return 0;
}
