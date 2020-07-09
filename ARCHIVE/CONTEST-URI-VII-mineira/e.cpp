#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 5e5+10;

int n;
int tree[MAXN];

void add (int k, int x) {
	// printf ("=%d %d\n", k, n);
	while (k <= n) {
		tree[k] += x;
		k += k&-k;
	}
}

int sum (int k) {
	int s = 0;
	while (k >= 1) {
		s += tree[k];
		k -= k&-k;
	}

	return s;
}

int main ()
{
	scanf ("%d", &n);
	int x;
	for (int i = 0; i < n; i++) {
		scanf ("%d", &x);
		printf ("%d", x-sum (x));
		add (x, 1);
		if (i < n-1)
			putchar (' ');
	}
	putchar ('\n');
	/*for (int i = 1; i <= n; i++) {
		printf ("%d ", tree[i]);
	}
	putchar ('\n');*/

	return 0;
}
