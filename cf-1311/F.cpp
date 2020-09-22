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

const int N = 3e5 + 10;

int n;
int x[N];
vector<pii> vec, vecVel;
set<int> st;
map<int, int> posVal;
ll neg[N], posit[N], qntNeg[N], qntPosit[N];

void add(ll *bit, int p, int v) {
	for(int i = p; i < N; i+=i&-i)
		bit[i] += v;
}

ll sum(ll *bit, int p) {
	ll ret = 0;
	for(int i = p; i; i-=i&-i)
		ret += bit[i];
	return ret;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> x[i];
	for(int i = 1; i <= n; i++) {
		int v;
		cin >> v;
		vec.push_back({x[i], v});
		st.insert(v);
	}
	sort(vec.begin(), vec.end());
	int idx = 1;
	for(int pr : st)
		posVal[pr] = idx++;


	ll ans = 0;
	ll sumZero = 0;
	int qntZero = 0;
	for(auto pr : vec) {
		int pos = pr.x;
		int vel = pr.y;
		int posBit = posVal[vel];
		if(vel == 0) {
			ans += sum(qntNeg, N-1)*pos - sum(neg, N-1);
			ans += qntZero*1LL*pos - sumZero;
			sumZero += pos;
			qntZero++;
		}
		else if(vel > 0) {
			ans += qntZero*1LL*pos - sumZero;
			ans += sum(qntNeg, N-1)*pos - sum(neg, N-1);

			ans += sum(qntPosit, posBit)*pos - sum(posit, posBit);
			add(qntPosit, posBit, 1);
			add(posit, posBit, pos);
		} else {
			ans += sum(qntNeg, posBit)*pos - sum(neg, posBit);
			add(qntNeg, posBit, 1);
			add(neg, posBit, pos);
		}
		// cout << "pos = " << pos << ", vel = " << vel << ", posBit = " << posBit << ", ans = " << ans << '\n';
	}
	cout << ans << '\n';
	

	return 0;
}
