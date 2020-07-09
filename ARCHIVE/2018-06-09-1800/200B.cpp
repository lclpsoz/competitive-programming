#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

int n;

int main ()
{
	scanf ("%d", &n);
	int x = 0;
	int y = 0;
	for (int i = 0; i < n; i++) {
		scanf ("%d", &x);
		y += x;
	}

	printf ("%.20lf\n", (double)y/n);

	return 0;
}
