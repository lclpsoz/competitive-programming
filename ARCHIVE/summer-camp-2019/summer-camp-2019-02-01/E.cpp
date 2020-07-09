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

map<int, int> mp;
map<int, vector<int>> mpVec;
int ans[N];
set<pii> st;
set<int> base;
vector<int> vec;

int main () {
    int n;
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf ("%d", &x);
        mp[x]++;
        mpVec[x].push_back (i);
    }
    
    for (pii p : mp) {
        st.insert ({p.y, p.x});
        base.insert (p.x);
    }
    for (int i = 1; i <= n; i++)
        if (!base.count (i))
            vec.push_back (i);
    for (pii p : st) {
        while (p.x > 1 or (p.x > 0 and p.y > n)) {
            int pos = mpVec[p.y].back();
            mpVec[p.y].pop_back();
            ans[pos] = vec.back();
            vec.pop_back ();
            p.x--;
        }
        if (!mpVec[p.y].empty())
            ans[mpVec[p.y].back()] = p.y;
    }
        
    for (int i = 1; i <= n; i++)
        printf ("%d%c", ans[i], " \n"[i==n]);

	return 0;
}
