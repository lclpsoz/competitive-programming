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

const int P = 5e6 + 10, N = 1e5 + 10;

int O, D;
bitset<P> not_prime;
bitset<N> vis;
vector<int> primes;
vector<pair<int, pii>> adj[N];
set<pair<ll, int>> st;

ll dij(int mini_edge) {
    st.clear();
    st.insert({0, O});
    vis.reset();
    // cout << mini_edge << '\n';
    while(!st.empty() && st.begin()->y!= D) {
        auto p = *st.begin();
        int v = p.y;
        ll w = p.x;
        st.erase(st.begin());
        if(vis[v]) continue;
        vis[v] = 1;
        for(auto nxt : adj[v])
            if(nxt.y.x >= mini_edge)
                st.insert({w+nxt.y.y, nxt.x});
    }

    if(st.empty()) return -1;
    else return st.begin()->x;
}

bool valid(int v, int mini_edge) {
    // cout << v << '\n';
    if(v == D) return true;
    if(vis[v]) return false;
    vis[v] = 1;
    for(auto p : adj[v])
        if(p.y.x >= mini_edge && valid(p.x, mini_edge))
            return true;
    return false;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

    for(int i = 2; i*i < P; i++)
        if(!not_prime[i])
            for(int j = i*i; j < P; j+=i)
                not_prime[j] = 1;

    primes.push_back(1);
    for(int i = 2; i < P; i++)
        if(!not_prime[i])
            primes.push_back(i);

    
    int n, m;
    cin >> n >> m >> O >> D;
    for (int i = 0; i < m; i++) {
        int u, v, A, Pr;
        cin >> u >> v >> A >> Pr;
        adj[u].push_back({v, {A, Pr}});
    }

    int l = 0, r = LEN(primes)-1;
    int q = 0;
    while(l < r) {
        assert(q++ < 25);
        int md = (l+r+1)/2;
        vis.reset();
        // cout << "l = " << l << " r = " << r << " md = " << md << " val = " << val << '\n';
        if(!valid(O, primes[md]))
            r = md-1;
        else
            l = md;
    }
    ll val = dij(primes[l]);
    if(val == -1)
        cout << "0 0\n";
    else
        cout << primes[l] << ' ' << val*primes[l] << '\n';

	return 0;
}
