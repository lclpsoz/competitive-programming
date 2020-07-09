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

int n, k;
int a, b;
char aa, bb;
vector<char> ans;

int main () {
    aa = 'G', bb = 'B';
    scanf ("%d %d  %d %d", &n, &k, &a, &b);
    if (a < b) {
        swap (a, b);
        swap (aa, bb);
    }
    
    int ax = k;
    for (int i = 1; i <= n and a > b; i++) {
        if (ax > 0) {
            ans.push_back (aa);
            --a;
            --ax;
        } else {
            ax = k;
            ans.push_back (bb);
            --b;
        }
        if (b < 0) {
            printf ("NO\n");
            exit (0);
        }
    }
    
    if (!ans.empty() and ans.back() == aa) {
        swap (aa, bb);
        swap (a, b);
    }
    while (a > 0 and a == b) {
        ans.push_back (aa);
        ans.push_back (bb);
        a--;
        b--;
    }
    
    for (char c : ans)
        putchar (c);
    putchar ('\n');
        
    
    
    
	return 0;
}
