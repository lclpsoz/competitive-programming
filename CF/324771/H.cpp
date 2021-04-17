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

template<typename T>
const T INF = (is_same<T, int>::value ? 1e9 : 1e18);
const ld EPS = 1e-9;
const int MOD = 1;

inline int fcmp (ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

inline int mod (ll x, int m = MOD) {
	int ret = (int)x%m;
	if (ret < 0)
		ret += m;
	return ret;
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

using hash_t = pair<int, int>;
const hash_t MODS = {1000000007, 982451653};
hash_t BASE = {313, 541};
vector<hash_t> _pow = {hash_t(1, 1)};

void gen_base()
{
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937 mt_rand(seed);
    int base1 = std::uniform_int_distribution<int>(300, MODS.first - 4)(mt_rand) | 1;
    int base2 = std::uniform_int_distribution<int>(300, MODS.second - 4)(mt_rand) | 1;
    if(base1 == base2)
        base2 += 2;
    BASE = {base1, base2};
}

inline hash_t operator * (const hash_t& a, const hash_t& b)
{
    return {int((a.first * 1LL * b.first) % MODS.first), int((a.second * 1LL * b.second) % MODS.second)};
}
inline hash_t operator * (const hash_t& a, const int b)
{
    return {int((a.first * 1LL * b) % MODS.first), int((a.second * 1LL * b) % MODS.second)};
}
inline hash_t operator + (const hash_t& a, const hash_t& b)
{
    return {(a.first + b.first) % MODS.first, (a.second + b.second) % MODS.second};
}
inline hash_t operator - (const hash_t& a, const hash_t& b)
{
    return {(a.first - b.first + MODS.first) % MODS.first, (a.second - b.second + MODS.second) % MODS.second};
}

struct shash
{
    int n;
    vector<hash_t> val;

    shash(const shash& o)
    {
        n = o.n;
        val = o.val;
    }

    shash(const string& _s = "")
    {
        n = 0;
        val = {hash_t(0, 0)};
        for(char c : _s)
            push_back(c);
    }

    void push_back(char c)
    {
        n++;
        while(LEN(_pow) < n)
            _pow.emplace_back(_pow.back() * BASE);
        val.emplace_back(val.back() + _pow[n - 1] * c);
    }

    void pop_back()
    {
        n--;
        val.pop_back();
    }

    hash_t substr(int p, int sz, int diff)
    {
		while(LEN(_pow) <= diff)
            _pow.emplace_back(_pow.back() * BASE);
        return (val[p + sz] - val[p]) * _pow[diff];
    }

    int size()
    {
        return n;
    }
};

inline int left(int root){ return 2 * root;}
inline int right(int root){ return 2 * root + 1;}

struct node
{
	hash_t val = {0, 0};
	node(){}
    void apply(int l, int r){}
};

const int N = 1e5 + 10;
hash_t v[N];
node t[4 * N];

node merge(node& l, node& r)
{
    node p;
    p.val = l.val + r.val;
    return p;
}

void build(int root, int l, int r)
{
    if(l == r)
    {
        t[root].val = v[l];
        return;
    }

    int mid = (l + r) / 2;
    build(left(root), l, mid);
    build(right(root), mid + 1, r);
    t[root] = merge(t[left(root)], t[right(root)]);
}
		
node query(int root, int l, int r, int ql, int qr)
{
    if(l > qr || r < ql)
        return node();

    if(l >= ql && r <= qr)
        return t[root];
    
    int mid = (l + r) / 2;
    node a = query(left(root), l, mid, ql, qr);
    node b = query(right(root), mid + 1, r, ql, qr);
    return merge(a, b);
}
	
void update(int root, int l, int r, int p, hash_t val)
{
    if(l > p || r < p) return;

    if(l == r)
    {
        t[root].val = val;
        return;
    }
    
    int mid = (l + r) / 2;
    update(left(root), l, mid, p, val);
    update(right(root), mid + 1, r, p, val);
    t[root] = merge(t[left(root)], t[right(root)]);
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	// gen_base();

	string s;
	cin >> s;

	if(LEN(s) < 7)
	{
		cout << "Goodbye, my love!" << endl;
		return 0;
	}

	shash sh(s);
	for(int i = 0; i < LEN(s); i++)
		v[i] = sh.substr(i, 1, 0);
	build(1, 0, LEN(s) - 1);

	multiset<hash_t> st;
	for(int i = 0; i <= LEN(s) - 7; i++)
		st.insert(sh.substr(i, 7, LEN(s) - i));

	string d = "desmond";
	shash dh(d);
	if(st.count(dh.substr(0, 7, LEN(s))))
	{
		cout << "I love you, Desmond!" << endl << 0 << endl;
		return 0;
	}

	int m; cin >> m;
	for(int k = 1; k <= m; k++)
	{
		int p;
		char c;
		cin >> p >> c;
		--p;
		for(int i = 0; i < 7; i++)
		{
			int j = p - i;
			if(j < 0 || j + 6 >= LEN(s)) continue;
			hash_t now = query(1, 0, LEN(s) - 1, j, j + 6).val;
			now = now * _pow[LEN(s) - j];
			st.erase(st.find(now));
		}

		update(1, 0, LEN(s) - 1, p, _pow[p] * c);

		for(int i = 0; i < 7; i++)
		{
			int j = p - i;
			if(j < 0 || j + 6 >= LEN(s)) continue;
			hash_t now = query(1, 0, LEN(s) - 1, j, j + 6).val;
			now = now * _pow[LEN(s) - j];
			st.insert(now);
		}

		if(st.count(dh.substr(0, 7, LEN(s))))
		{
			cout << "I love you, Desmond!" << endl << k << endl;
			return 0;
		}
	}

	cout << "Goodbye, my love!" << endl;

	return 0;
}
