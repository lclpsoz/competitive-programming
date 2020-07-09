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

const int N = 2e5+10;

int n, q;
int ans[N], vals[N];
map<int, vector<int>> base;
map<int, vector<pii>> qry;
vector<int> uniq;
set<int> st;
int bit[N];

int sum (int p) {
    int r = 0;
    for (; p >= 1; p-=p&-p)
        r += bit[p];
    return r;
}

void add (int p, int v) {
    for (; p < N; p+=p&-p)
        bit[p] += v;
}

int main () {
    scanf ("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        int v;
        scanf ("%d", &v);
        vals[i] = v;
        base[v].push_back (i);
    }
    
    for (int i = 0; i < q; i++) {
        int p, v;
        scanf ("%d %d", &p, &v);
        ++p;
        if (vals[p] != v) {
            qry[vals[p]].push_back ({p, -1}); // Remove    
            vals[p] = v;
        }
        qry[v].push_back ({p, i});
        uniq.push_back (v);
    }
    
    sort (uniq.begin(), uniq.end());
    uniq.resize (unique (uniq.begin(), uniq.end()) - uniq.begin());
    
    
    for (int now : uniq) {
        vector<int> &vec1 = base[now];
//         printf ("base: ");
        for (int p : vec1) {
            st.insert (p);
            add (p, 1);
//             printf ("%d ", p);
        }
//         putchar ('\n');
        vector<pii> &vec2 = qry[now];
        for (pii pp : vec2) {
            int p = pp.x;
            int pAns = pp.y;
            if (pAns == -1) {
//                 printf ("|pAns = %d\n", pAns);
//                 printf ("|now = %d, p = %d\n", now, p);
                if (st.count (p)) {
                    st.erase (p);
                    add (p, -1);
//                     printf ("|sum : %d\n", sum (p+2));
                }
            }
            else {
//                 printf ("|pAns: %d\n", pAns);
//                 printf ("|p: %d\n", p);
//                 for (int va : st)
//                     printf ("|%d\n", va);
                if (st.count (p) == 0) {
                    add (p, 1);
                    st.insert (p);
                }
                ans[pAns] = sum (p) - 1;
//                 if (it != st.end() and *it == p)
//                     ans[pAns]--;
            }
        }
        for (int v : st)
            add (v, -1);
        st.clear();
//         memset (bit, 0, sizeof bit);
//         memset (aux, 0, sizeof aux);
    }
    for (int i = 0; i < q; i++)
        printf ("%d\n", ans[i]);
    

	return 0;
}
