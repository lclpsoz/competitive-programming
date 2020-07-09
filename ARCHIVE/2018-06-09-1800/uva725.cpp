#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;


const int MAXN = 1e5+10;

int n;
bool mark[MAXN];
vector<int> valid;

bool func (int x) {
	int arr[10];
	memset (arr, 0, sizeof (arr));
	if (x < 1e4) arr[0] = true;
	while (x) {
		if (arr[x%10]) return false;
		arr[x%10] = true;
		x/=10;
	}

	return true;
}

bool f (int x, int y) {
	int arr[10];
	memset (arr, 0, sizeof (arr));
	if (x < 1e4) arr[0] = true;
	if (y < 1e4 && arr[0]) return false;
	while (x) {
		if (arr[x%10]) return false;
		arr[x%10] = true;
		x/=10;
	}
	x = y;
	while (x) {
		if (arr[x%10]) return false;
		arr[x%10] = true;
		x/=10;
	}

	return true;
}

int main ()
{
	for (int i = 1234; i < 1e5; i++)
		if (func (i)) {
			mark[i] = true;
			valid.pb (i);
		}
	bool ts = false;
	while (scanf ("%d", &n), n) {
		if (ts) putchar ('\n');
		ts = true;
		int q = 0;
		auto r = valid.begin();
		while (r != valid.end() && (*r)*n <= 99999) {
			if (mark[(*r)*n] && f (*r, *r*n)) {
				q++;
				printf ("%05d / %05d = %d\n", (*r) * n, *r, n);
			}
			r++;
		}
		if (!q) printf ("There are no solutions for %d.\n", n);
	}

	return 0;
}
