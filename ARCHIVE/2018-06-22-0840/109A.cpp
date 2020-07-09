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

const int MAXN = 1e6+10;

pair<int, pii> arr[MAXN];

int main ()
{
	int n;
	for (int i = 0; i < MAXN; i++)
		arr[i] = {-1, {-1, -1}};
	scanf ("%d", &n);
	n+=4;
	arr[0] = {0, {0, 0}};
	for (int i = 4; i <= n; i+=4)
		arr[i] = {arr[i-4].x+1, {arr[i-4].y.x+1, 0}};

	for (int i = 7; i <= n; i++)
		if (arr[i-7].x > -1 && (arr[i].x == -1 || arr[i].x > arr[i-7].x+1))
			arr[i] = {arr[i-7].x+1, {arr[i-7].y.x, arr[i-7].y.y+1}};

	/*for (int i = 0; i < n; i++) {
		printf ("%d: ", i);
		for (int j = 0; j < arr[i].y.x; j++) putchar ('4');
		for (int j = 0; j < arr[i].y.y; j++) putchar ('7');
		putchar ('\n');
	}*/

	n-=4;
	if (arr[n].x == -1)
		printf ("-1\n");
	else {
		for (int j = 0; j < arr[n].y.x; j++) putchar ('4');
		for (int j = 0; j < arr[n].y.y; j++) putchar ('7');
		putchar ('\n');
	}

	return 0;
}
