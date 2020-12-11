#include "bits/stdc++.h"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/pb_ds/assoc_container.hpp"
using namespace std;
////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define LEN(x) ((int)(x).size())
#define ALL(x) x.begin(), x.end()
using ll = long long;
using llu = long long unsigned;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vpii = vector<pii>;

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

const int N = 4e6, S = 1e6 + 100;

int n, q;
int trie[N][12];
int v[S];
string s;
int lst = 1;

void ins(int p, int id) {
    if(trie[id][10] == -1)
        trie[id][10] = 0;
    trie[id][10]++;
    
    if(LEN(s) > p) {
        // cout << p << ' ' << (int)s[p] << ' ' << id << '\n';
        if(trie[id][v[p]] == -1)
            trie[id][v[p]] = lst++;
        ins(p+1, trie[id][v[p]]);
    }
}

int qry(int p, int id) {
    if(id == -1) return 0;
    // cout << "|" << trie[id][10] << '\n';
    if(LEN(s) == p) return trie[id][10];
    // cout << p << ' ' << id << ' ' << (int)s[p] << '\n';
    return qry(p+1, trie[id][v[p]]);
}

int main () {
	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.precision(10);
    memset(trie, -1, sizeof trie);

    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < LEN(s); j++) {
            if(s[j] <= 'o')
                v[j] = (s[j] - 'a') / 3 + 2;
            else if(s[j] <= 's')
                v[j] = 7;
            else if(s[j] <= 'v')
                v[j] = 8;
            else
                v[j] = 9;
            // cout << v[j] << '\n';
        }
        ins(0, 0);
    }
    // cout << "queries\n";
    for(int i = 0; i < q; i++) {
        cin >> s;
        for(int j = 0; j < LEN(s); j++) v[j] = s[j]-'0';
        cout << qry(0, 0) << '\n';
    }

	return 0;
}
