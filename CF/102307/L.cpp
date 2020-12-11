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

const int DBG = true;
int val_target = 10;

const int N = 102, MAXV = 1e6 + 10;

vector<int> a, vals;
int qnt[MAXV];
int dp[MAXV];


int recu(int x) {
    memset(qnt, 0, sizeof qnt);
    while(x) {
        if(!dp[x]) return false;
        qnt[dp[x]]++;
        x-=dp[x];
    }

    return true;
}

int qry(int est) {
    recu(est);
    cout << "1\n";
    set<int> st;
    for(int i = 0; i < LEN(a); i++) {
        if(st.insert(a[i]).y)
            cout << qnt[a[i]] << " \n"[i==LEN(a)-1];
        else
            cout << 0 << " \n"[i==LEN(a)-1];
    }
    cout.flush();
    string s;
    if(DBG)
        return ((est > val_target) ? 1 : (est < val_target) ? -1 : 0);
    cin >> s;
    if(s == "green") return -1;
    else if(s == "red") return 1;
    return 0;
}

void ans(int v) {
    cout << "2\n";
    cout << v << '\n';
    exit(0);
}

void no() { cout << "2\n-1\n"; }

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

    int n, x;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x;
        a.push_back(x);
    }
    
    dp[0] = 1;
    for(int v : a)
        for(int i = v; i < MAXV; i++)
            if(dp[i-v])
                dp[i] = v;
    
    for(int i = 1; i <= 1000000; i++)
        if(dp[i])
            vals.push_back(i);
    int l = 0, r = LEN(vals)-1;
    while(l < r) {
        int md = (l+r)/2;
        int v = qry(vals[md]);
        if(v == 0)
            ans(vals[md]);
        else if(v == -1)
            l = md+1;
        else
            r = md-1;
    }
    int v = qry(vals[l]);
    if(v == 0)
        ans(vals[l]);
    else if(v == -1) {
        if(l == LEN(vals)-1) {
            if(vals[l] == 999999)
                ans(1000000);
            else
                no();
        }
        else if(vals[l+1] == vals[l]+2)
            ans(vals[l]+1);
        else
            no();
    } else {
        if(l == 0) {
            if(vals[l] == 2)
                ans(1);
            else
                no();
        } else if(vals[l]-vals[l-1] == 2)
            ans(vals[l]-1);
        else
            no();
    }

	return 0;
}
