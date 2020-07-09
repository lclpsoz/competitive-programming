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

char str[1010];
int arr[400];

int main ()
{
	while (scanf ("%s", str) != EOF) {
		for (int i = 0; str[i] != '\0'; i++)
			arr[str[i]]++;
		int ans = 0;
		for (int i = 0; i < 400; i++) {
			if (arr[i]&1)
				ans++;
			arr[i] = 0;
		}
		printf ("%d\n", max (0, ans-1));
	}

	return 0;
}
