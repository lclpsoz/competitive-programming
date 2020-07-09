#include <bits/stdc++.h>
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define pb push_back
#define foreach(x, v) for (typeof (v).begin() x=(v).begin(); x !=(v).end(); ++x)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define D(x) cerr << #x " is " << (x) << endl
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

////////////////////////// Solution starts below. //////////////////////////////

const int MAXN = 1e6;

int n;
int dir[MAXN];
int esq[MAXN];

int main ()
{
	scanf ("%d ", &n);
	char c;
	stack<char> st;
	int comp = 0;
	for (int i = 0; i < n; i++) {
		c = getchar ();
		while (c != '\n') {
			if (c == ')') {
				if (!st.empty() && st.top() == '(')
					st.pop();
				else
					st.push (')');
			} else
				st.push ('(');
			c = getchar ();
		}
		int l, r;
		l = r = 0;
		if (st.empty()) {
			comp++;
		} else {
			while (!st.empty()) {
				if (st.top() == '(') l++;
				else r++;
				st.pop();
			}
			if (l && r == 0)
				esq[l]++;
			else if (l == 0 && r)
				dir[r]++;
		}
	}
	ll ans = 1LL*comp*comp;
	for (int i = 1; i < MAXN; i++)
		ans += 1LL*dir[i]*esq[i];

	printf ("%lld\n", ans);

	return 0;
}
