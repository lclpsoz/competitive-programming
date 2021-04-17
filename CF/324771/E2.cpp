#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

#define LEN(x) (int)x.size()
#define ALL(x) x.begin(), x.end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;
using vpii = vector<pii>;

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

template<typename T>
const T INF = (is_same<T, int>::value ? 1e9 : 1e18);
const int MOD = 1e9 + 7;
const double EPS = 1e-9;

inline int fcmp(double x, double y)
{ return (x < y + EPS ? (x < y - EPS ? -1 : 0) : 1);}

const int N = 1e5 + 10;
int t[N];

int n;
ll m;
ll _lcm(ll a, ll b)
{
    if(a > INF<int> + m || b > INF<int> + m)
        return INF<int> + m + 1;
    return lcm<ll>(a, b);
}

bitset<N> can_divide;
void fill_can_divide () {
	map<int, int> mp;
	for (int i = 0; i < n; i++)
		mp[t[i]]++;
	
	vi vals;
	for (int i = 0; i < n; i++)
		vals.push_back(t[i]);
	sort(ALL(vals));
	vals.resize(unique(ALL(vals)) - vals.begin());
	set<int> v_div;
	for (int v : vals) {
		for (ll i = 2*v; i <= vals.back();) {
			int nxt_val = *lower_bound(ALL(vals), i);
			if (nxt_val == i) {
				v_div.insert(v);;
				break;
			}
			i = (nxt_val/v + 1)*1LL*v;
		}
	}
	for (int i = 0; i < n; i++)
		if (mp[t[i]] > 1 or v_div.count(t[i]))
			can_divide[i] = true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> t[i];

    fill_can_divide();
    vector<ll> pref(n + 1), suf(n + 1);
    pref[0] = 1;
    for(int i = 0; i < n; i++)
        pref[i + 1] = _lcm(pref[i], t[i]);
    suf[n] = 1;
    for(int i = n - 1; i >= 0; i--)
        suf[i] = _lcm(suf[i + 1], t[i]);

    for(int i = 0; i < n; i++)
    {
        // cout << i << ": " << pref[i] << " * " << suf[i + 1] << endl;
        ll a = _lcm(pref[i], suf[i + 1]);
        if(a > INF<int> + m || can_divide[i])
            cout << "Never" << '\n';
        else
            cout << a - m << '\n';
    }

    return 0;
}