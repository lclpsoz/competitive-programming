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

set<char> st;

int main () {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        bool ans = true;
        for (char c : s) {
            if (st.count (c)) ans = false;
            st.insert (c);
        }
        st.clear();
        if (!ans)
            cout << "No\n";
        else {
            sort (s.begin(), s.end());
            ans = true;
            for (int i = 1; i < len (s); i++)
                if (s[i] != s[i-1]+1)
                    ans = false;
            cout << (ans ? "Yes" : "No") << '\n';
        }
            
    }

	return 0;
}
