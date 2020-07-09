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
typedef long double ld;
const int INF = 1e9;

const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

////////////////////////// Solution starts below. //////////////////////////////

const int MAXN = 1e5+10;

int n;
string str;
int r[MAXN];
int c[MAXN];
vector<int> his;

int main ()
{
	cin >> n;
	cin >> str;
	for (int i = 0; i < n; i++)
		scanf ("%d", &r[i]);
	for (int i = 0; i < n; i++)
		scanf ("%d", &c[i]);

	int ans = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '1') {
			ans += c[i];
			for (int j = i; j < r[i]; j++)
				str[j] = (str[j] == '1' ? '0' : '1');
		}
		// cout << str << '\n';
	}

	cout << ans << '\n';

	return 0;
}
