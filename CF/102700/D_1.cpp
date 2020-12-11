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

const int MOD = 1e9 + 7;
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////


void prt(vector<int> v) {
    for(int i = 0; i < LEN(v); i++)
        cout << v[i] << " \n"[i==LEN(v)-1];
}

vector<int> mult(const vector<int> &v1, const vector<int> &v2) {
    vector<int> v3 = vector<int>(LEN(v1));
    for(int i = 0; i < LEN(v3); i++)
        for(int j = 0; j < LEN(v3); j++)
            v3[(i+j)%LEN(v3)] += v1[i]*v2[j];
    return v3;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

    vector<int> v1, v2, v3;
    int n, k, m;
    cin >> n >> k >> m;
    v1 = vector<int>(m);
    for(int i = 1; i <= k; i++)
        if(i%m)
            v1[i%m] += 1;
    prt(v1);
    v2 = v1;
    v3 = mult(v1, v2);
    prt(v3);
    v3 = mult(v3, v1);
    prt(v3);
    v3 = mult(v3, v1);
    prt(v3);
    cout << "fast:" << '\n';
    prt(mult(mult(v1, v1), mult(v1, v1)));

	return 0;
}
