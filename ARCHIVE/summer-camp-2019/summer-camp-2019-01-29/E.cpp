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

const int MV = 1e5+10;
const int N = 3e5+1000;
int n, m, q;
int link[N], size[N];
map<string, int> mp;
int lst;


int find (int a) {
    return a == link[a] ? a : link[a] = find (link[a]);
}

bool same (int a, int b) {
//     printf ("|%d %d -> %d %d\n", a, b, find (a), find (b));
    return find (a) == find (b);
    
}

void unite (int a, int b) {
    if (same (a, b)) return;
    a = find (a);
    b = find (b);
    if (size[a] > size[b]) swap (a, b);
    size[b] += size[a];
    link[a] = b;
}

bool func (int a, int b, int ty) {
    if ((ty == 1 and (same (a, b+MV) or same (a+MV, b))) or
        (ty == 2 and same (a, b)))
        return false;
    if (ty == 1) {
        unite (a, b);
        unite (a+MV, b+MV);
    } else {
        unite (a, b+MV);
        unite (a+MV, b);
    }
    return true;
}

int main () {
     cin.tie (0);
     ios::sync_with_stdio (false);
    cin >> n >> m >> q;
    lst = 2e5+100;
    // Syn
    for (int i = 1; i <= n; i++)
        size[i] = 1, link[i] = i;
    // Inv
    for (int i = 1+MV; i <= n+MV; i++)
        size[i] = 2, link[i] = lst++;
    
    for (int i = n+MV+1; i < N; i++)
        size[i] = 2, link[i] = i;
    
    lst = 1;
    for (int i = 1; i <= n; i++) {
        string str;
        cin >> str;
        mp[str] = lst++;
    }
    
    while (m--) {
        string str;
        int opt, u, v;
        cin >> opt;
        cin >> str;
        u = mp[str];
        cin >> str;
        v = mp[str];
        
//         cout << u << ' ' << v << ' ' <<opt << '\n';
        if (!func (u, v, opt))
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    
//     for (int i = 1; i <= n; i++)
//         printf ("%d: %d %d\n", i, link[1][i], link[i]);
    while (q--) {
        string str;
        int u, v;
        cin >> str;
        u = mp[str];
        cin >> str;
        v = mp[str];
//         cout << "q: ";
//         cout << u << ' ' << v << '\n';
        if (u == 0 or v == 0)
            cout << 3 << '\n';
        else if (same (u, v))
            cout << 1 << '\n';
        else if ((same (u, v+MV) or same (u+MV, v)))
            cout << 2 << '\n';
        else
            cout << 3 << '\n';
    }

	return 0;
}
