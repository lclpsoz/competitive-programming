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

const int M = 110;

int n, d;
char str[M];
vector<pii> vec;
set<int> st;

int main () {
    scanf ("%d %d", &n, &d);
    while (n--) {
        scanf (" %[^\n] ", str);
        int qnt = 0;
        for (int i = 0; str[i] != '\0'; i++)
            if (tolower (str[i]) >= 'a' and tolower (str[i]) <= 'z') ++qnt;
        vec.push_back ({qnt, (int)tolower (str[0])});
    }
    sort (vec.begin(), vec.end(), greater<pii>());
    int ans = 0;
    for (auto p : vec) {
        if (st.count (p.y) == 0 and len (st) < d) {
            st.insert (p.y);
            ans += p.x;
        }
    }
    printf ("%d\n", ans);

	return 0;
}
