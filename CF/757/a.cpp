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

const int N = 1e5+10;

char str[N];
char arr[] = "Bulbasaur";
int qnt[400];
int novo[400];

int main ()
{
	for (int i = 0; arr[i] != '\0'; i++)
		qnt[arr[i]]++;
	scanf ("%s", str);
	for (int i = 0; str[i] != '\0'; i++)
		novo[str[i]]++;
	int ans = INF;
	for (int i = 0; i < 400; i++)
		if (qnt[i])
			ans = min (ans, novo[i]/qnt[i]);

	cout << ans << '\n';

	return 0;
}
