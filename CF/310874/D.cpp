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

struct aho_corasick
{
    vector<string> dict;
    vector<vector<int>> trie;
    vector<vector<int>> terminal;
    vector<int> fail;
    int sigma;
	queue<int> q;

    aho_corasick(int alphabet_size = 26)
    {
        sigma = alphabet_size;
		trie.emplace_back(sigma, -1);
		terminal.emplace_back();
		lazy.emplace_back(false);
    }

	vector<bool> lazy;

	void add_node(int p, int c)
	{
		trie[p][c] = LEN(trie);
		trie.emplace_back(sigma, -1);
		terminal.emplace_back();
		lazy.emplace_back(false);
	}
	
	void attach(int node, int mark)
	{
		terminal[node].emplace_back(mark);
		lazy[node] = true;
	}

	int query(int node)
	{
		vi now;
		while(node)
			merge(now, terminal[fail[node]]), node = fail[node];
		return LEN(now);
	}

    void build()
    {

        fail = vector<int>(LEN(trie), -1);
        for(int c = 0; c < sigma; c++)
            if(trie[0][c] == -1) trie[0][c] = 0;
            else q.emplace(trie[0][c]), fail[trie[0][c]] = 0;

        while(!empty(q))
        {
            int node = q.front();
            q.pop();

            for(int c = 0; c < sigma; c++)
            {
                int& cur = trie[node][c];
                if(cur == -1) continue;
            
                q.emplace(cur);

                int s = fail[node];
                while(trie[s][c] == -1)
                    s = fail[s];
                fail[cur] = trie[s][c];
            }
        }
    }

	void update()
	{
        for(int c = 0; c < sigma; c++)
            if(trie[0][c] != -1) q.emplace(trie[0][c]);
		
		while(!empty(q))
        {
            int node = q.front();
            q.pop();
			lazy[node] = false;

            for(int c = 0; c < sigma; c++)
            {
                int& cur = trie[node][c];
                if(cur == -1) continue;
            
                q.emplace(cur);

                if(!empty(terminal[fail[cur]]))
                    merge(terminal[cur], terminal[fail[cur]]);
            }
        }
	}

    void merge(vector<int>& a, vector<int>& b)
    {
		vi c;
		int i = 0, j = 0;
		while(i < LEN(a) || j < LEN(b))
		{
			if(i == LEN(a))
			{
				if(empty(c) || b[j] != c.back())
					c.emplace_back(b[j]);
				j++;
			}
			else if(j == LEN(b))
			{
				if(empty(c) || a[i] != c.back())
					c.emplace_back(a[i]);
				i++;
			}
			else
			{
				if(a[i] < b[j])
				{
					if(empty(c) || a[i] != c.back())
						c.emplace_back(a[i]);
					i++;
				}
				else
				{
					if(empty(c) || b[j] != c.back())
						c.emplace_back(b[j]);
					j++;
				}
			}
		}
		swap(a, c);
	}
};

const int N = 1e5 + 10, B = 400;

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int tt; cin >> tt;
	while(tt--)
	{
		int n; cin >> n;
		aho_corasick aho;
		for(int i = 1; i < n; i++)
		{
			int p; char c;
			cin >> p >> c;
			aho.add_node(p - 1, c - 'a');
		}

		aho.build();

		int q; cin >> q;
		int cnt = 0;

		for(int i = 0; i < q; i++)
		{
			int t; cin >> t;
			if(t == 1)
			{
				cnt++;
				int k; cin >> k;
				while(k--)
				{
					int node; cin >> node;
					aho.attach(node - 1, i);
				}
			}
			else
			{
				int node; cin >> node;
				cout << aho.query(node - 1) << endl;
			}


			if(cnt == B)
				aho.update(), cnt = 0;
		}
	}

	return 0;
}
